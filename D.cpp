#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
#define N 500006
#define lc (tr[id].c[0])
#define rc (tr[id].c[1])
#define key (tr[tr[root].c[1]].c[0])
struct tree
{
    int fa,sum,c[2],lz,v;
}tr[N];
struct point
{
    int v,id;
    bool operator<(const point a)const
    {
        if(a.v==v)return id<a.id;
        else return v<a.v;
    }
}so[N/5];
int tot,root,n;
int xia[N];
int newpoint(int d,int f)
{
    tr[tot].sum=1;
    tr[tot].v=d;
    tr[tot].c[0]=tr[tot].c[1]=-1;
    tr[tot].lz=0;
    tr[tot].fa=f;
    return tot++;
}
void push(int id)
{
    int lsum,rsum;
    if(lc==-1)lsum=0;
    else lsum=tr[lc].sum;
    if(rc==-1)rsum=0;
    else rsum=tr[rc].sum;
    tr[id].sum=lsum+rsum+1;
}
int build(int l,int r,int v)
{
    if(r<l)return -1;
    int mid=(r+l)>>1;
    int ro=newpoint(mid,v);
    xia[mid]=ro;
    tr[ro].c[0]=build(l,mid-1,ro);
    tr[ro].c[1]=build(mid+1,r,ro);
    push(ro);
    return ro;
}
void lazy(int id)
{
    if(tr[id].lz)
    {
        swap(lc,rc);
        tr[lc].lz^=1;
        tr[rc].lz^=1;
        tr[id].lz=0;
    }
}

void xuanzhuan(int x,int k)
{
    if(tr[x].fa==-1)return ;
    int fa=tr[x].fa;
    int w;
    lazy(fa);
    lazy(x);
    tr[fa].c[!k]=tr[x].c[k];
    if(tr[x].c[k]!=-1)tr[tr[x].c[k]].fa=fa;
    tr[x].fa=tr[fa].fa;
    tr[x].c[k]=fa;
    if(tr[fa].fa!=-1)
    {
        w=tr[tr[fa].fa].c[1]==fa;
        tr[tr[fa].fa].c[w]=x;
    }
    tr[fa].fa=x;
    push(fa);
    push(x);
}

void splay(int x,int goal)
{
    if(x==-1)return ;
    lazy(x);
    while(tr[x].fa!=goal)
    {
        int y=tr[x].fa;
        lazy(tr[y].fa);
        lazy(y);
        lazy(x);
        bool w=(x==tr[y].c[1]);
        if(tr[y].fa!=goal&&w==(y==tr[tr[y].fa].c[1]))xuanzhuan(y,!w);
        xuanzhuan(x,!w);
    }
    if(goal==-1)root=x;
    push(x);
}
int next(int id)
{
    lazy(id);
    int p=tr[id].c[1];
    if(p==-1)return id;
    lazy(p);
    while(tr[p].c[0]!=-1)
    {
        p=tr[p].c[0];
        lazy(p);
    }
    return p;
}
int main()
{
    while(scanf("%d",&n),n)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&so[i].v);
            so[i].id=i;
        }
        sort(so+1,so+n+1);
        so[0].id=0;
        tot=0;
        int d,l;
        root=build(0,n+1,-1);
        for(int i=1;i<=n;i++)
        {
            int ro=xia[so[i].id];
            int ne;
            splay(ro,-1);
            d=tr[tr[root].c[0]].sum;
            l=xia[so[i-1].id];
            ne=next(ro);
            splay(l,-1);
            splay(ne,root);
            lazy(root);
            lazy(tr[root].c[1]);
            tr[key].lz^=1;
            if(i!=1)printf(" ");
            printf("%d",d);
        }
        printf("\n");
    }
    return 0;
}