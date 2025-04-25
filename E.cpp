#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=2*100010;
int root;
int N;
int ch[maxn][2];
int pre[maxn];
int a[maxn];
int size[maxn];
int key[maxn];
int add[maxn];
int rev[maxn];
int s[maxn];
int tot2;
int tot1;
#define Key_value ch[ch[root][1]][0]
void NewNode(int &r,int f,int val)
{
    if(tot2)r=s[tot2--];
    else r+=++tot1;
    ch[r][0]=ch[r][1]=0;
    pre[r]=f;
    size[r]=1;
    key[r]=val;
    rev[r]=0;
    add[r]=0;
}
void pushup(int r)
{
    size[r]=size[ch[r][0]]+size[ch[r][1]]+1;
}
void build(int &x,int l,int r,int f)
{
    if(l>r)return ;
    int mid=(l+r)>>1;
    NewNode(x,f,a[mid]);
    build(ch[x][0],l,mid-1,x);
    build(ch[x][1],mid+1,r,x);
    pushup(x);
}
void init()
{
    root=tot1=tot2=0;
    ch[root][0]=ch[root][1]=size[root]=key[root]=add[root]=pre[root]=0;
    rev[root]=0;
    NewNode(root,0,-1);
    NewNode(ch[root][1],root,-1);
    build(Key_value,1,N,ch[root][1]);
    pushup(ch[root][1]);
    pushup(root);
}
void update_add(int r,int x)
{
    if(!r)return ;
    add[r]+=x;
    key[r]+=x;
}
void update_rev(int r)
{
    if(!r)return ;
    swap(ch[r][1],ch[r][0]);
    rev[r]^=1;
}
void pushdown(int r)                               //从r号结点开始向下更新
{
    if(add[r])                                     //如果add数组可以更新
    {
        update_add(ch[r][0],add[r]);
        update_add(ch[r][1],add[r]);
        add[r]=0;
    }
    if(rev[r])                                      //如果rev数组可以更新
    {
        update_rev(ch[r][0]);
        update_rev(ch[r][1]);
        rev[r]=0;
    }
}
 
void Rotate(int x,int kind)
{
    int y=pre[x];
    pushdown(y);
    pushdown(x);
    ch[y][!kind]=ch[x][kind];
    pre[ch[x][kind]]=y;
    if(pre[y])ch[pre[y]][ch[pre[y]][1]==y]=x;
    pre[x]=pre[y];
    ch[x][kind]=y;
    pre[y]=x;
    pushup(y);
}
void Splay(int r,int goal)
{
    pushdown(r);
    while(pre[r]!=goal)
    {
        if(pre[pre[r]]==goal)
        {
            pushdown(pre[r]);
            pushdown(r);
            Rotate(r,ch[pre[r]][0]==r);
        }
        else
        {
            pushdown(pre[pre[r]]);
            pushdown(pre[r]);
            pushdown(r);
            int y=pre[r];
            int kind=(ch[pre[y]][0]==y);
            if(ch[y][kind]==r)
            {
                Rotate(r,!kind);
                Rotate(r,kind);
            }
            else
            {
                Rotate(y,kind);
                Rotate(r,kind);
            }
        }
    }
    pushup(r);
    if(goal==0)root=r;
}
int get_kth(int r,int k)
{
    pushdown(r);
    int t=size[ch[r][0]]+1;
    if(t==k)return r;
    if(t>k)return get_kth(ch[r][0],k);
    else return get_kth(ch[r][1],k-t);
}
void change(int &poss,int k)                         //让数组中[pos,k]的数放入可被更改
{                                                //的一棵树中
    int pos=get_kth(root,poss);                     // (根节点序号为Key_value)
    Splay(pos,0);
    int tmp=size[ch[root][0]]+1;
    Splay(get_kth(root,1),0);                        //就位
    Splay(get_kth(root,tmp),root);
    tmp=Key_value;
    Key_value=0;
    pushup(ch[root][1]);
    pushup(root);
    Splay(get_kth(root,size[root]-1),0);
    Key_value=tmp;
    pre[Key_value]=ch[root][1];
    pushup(ch[root][1]);
    pushup(root);
    Splay(get_kth(root,1),0);
    Splay(get_kth(root,k+2),root);
}
void Add(int &poss,int k2,int x)                       //[poss,poss+k2]区间所有值加x
{
    change(poss,k2);
    update_add(Key_value,x);
    pushup(ch[root][1]);
    pushup(root);
    poss=2;
}
void Reverse(int &poss,int k1)                        //翻转[poss,poss+k1]的值
{
    change(poss,k1);
    update_rev(Key_value);
    pushup(ch[root][1]);
    pushup(root);
    poss=2;
}
 
//在序号为pos处插入x
void Insert(int &poss,int x)
{
    //将pos放到0号点下方
    int pos=get_kth(root,poss);
    Splay(pos,0);
    //
    Splay(get_kth(root,size[ch[root][0]]+2),root);
    NewNode(Key_value,ch[root][1],x);
    pushup(ch[root][1]);
    pushup(root);
}
void erase(int r)
{
    if(r)
    {
        s[++tot2]=r;
        erase(ch[r][0]);
        erase(ch[r][1]);
    }
}
//删除操作
void Delete(int &poss)
{
    int pos=get_kth(root,poss);
    Splay(pos,0);
    int tmp=size[ch[root][0]]+1;
    //就位
    Splay(get_kth(root,tmp-1),0);
    Splay(get_kth(root,tmp+1),root);
    //清除
    erase(Key_value);
    pre[Key_value]=0;
    Key_value=0;
    //更新
    pushup(ch[root][1]);
    //更新
    pushup(root);
    //更新指针
    if(tmp==size[root])poss=2;
    else poss=tmp;
}
//光标移动
void Move(int &poss,int x)
{
    int pos=get_kth(root,poss);
    if(x==1)
    {
        Splay(pos,0);
        int tmp=size[ch[root][0]];
        if(size[ch[root][0]]==1)tmp=size[root]-1;
        poss=tmp;
        //pos=get_kth(root,tmp);
    }
    else
    {
        Splay(pos,0);
        int tmp=size[ch[root][0]]+2;
        if(tmp==size[root])tmp=2;
        poss=tmp;
        //pos=get_kth(root,tmp);
    }
}
//询问
int Query(int &poss)
{
    int pos=get_kth(root,poss);
    Splay(pos,0);
    return key[root];
}
int main()
{
    int n,m,k1,k2;
    int t=1;
    while(scanf("%d%d%d%d",&n,&m,&k1,&k2)!=EOF)
    {
        N=n;
        if(n==0&&m==0&&k1==0&&k2==0)
            break;
        printf("Case #%d:\n",t++);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        int poss=2;
        int sum=n;
        init();
        for(int i=1;i<=m;i++)
        {
            char a[50];
            scanf("%s",a);
            if(a[0]=='q')
            {
                int res=Query(poss);
                printf("%d\n",res);
            }
            else if(a[0]=='r')
            {
                Reverse(poss,k1);
            }
            else if(a[0]=='i')
            {
                int x;
                sum+=1;
                scanf("%d",&x);
                Insert(poss,x);
            }
            else if(a[0]=='d')
            {
                sum-=1;
                Delete(poss);
            }
            else if(a[0]=='m')
            {
                int x;
                scanf("%d",&x);
                if(x==1)
                {
                    if(poss==2)poss=sum+1;
                    else poss-=1;
                }
                if(x==2)
                {
                    if(poss==sum+1)poss=2;
                    else poss+=1;
                }
            }
            else if(a[0]=='a')
            {
                int x;
                scanf("%d",&x);
                Add(poss,k2,x);
            }
        }
    }
    return 0;
}