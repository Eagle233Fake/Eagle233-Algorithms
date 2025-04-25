#include<iostream>
#include<cstring>
#include<queue>
#include<stdio.h>
#include<string>
using namespace std;
#define maxn 300

struct node {
    int val;
    bool haveVal;
    int l,r;
} tree[300];
int root,len;
bool ok;

bool read_input() {
    string s;
    ok = true;
    root = 0,len=1,tree[0].l=-1,tree[0].r=-1,tree[0].haveVal=false;
    for (;;) {
        if (!(cin>>s))return false;
        if (s=="()")return true;
        int v,now=root;
        sscanf(&s[1], "%d", &v);
        int i=s.find(',')+1;
        while (s[i] != ')') {
            if (s[i] == 'L') {
                if (tree[now].l == -1) {
                    tree[now].l = len++;
                    tree[tree[now].l].l=-1,tree[tree[now].l].r=-1,tree[tree[now].l].haveVal=false;
                }
                now = tree[now].l;
            }
            else{
                if (tree[now].r == -1){
                    tree[now].r = len++;
                    tree[tree[now].r].l=-1,tree[tree[now].r].r=-1,tree[tree[now].r].haveVal=false;
                }
                now = tree[now].r;
            }
            i++;
        }
        if (tree[now].haveVal) {
            ok = false;
        }
        tree[now].val = v;
        tree[now].haveVal = true;
    }
}

int main() {
    while (read_input()) {
        if (!ok) {
            cout << "not complete" << endl;
            continue;
        }
        string s="";
        queue<int> q;
        q.push(root);
        int now;
        while (q.size()) {
            now = q.front(); q.pop();
            if (!tree[now].haveVal) {
                s= "not complete";
                break;
            }
            else {
                if (s == "")
                    s += to_string(tree[now].val);
                else
                    s += " "+to_string(tree[now].val);
            }
            if(tree[now].l!=-1)q.push(tree[now].l);
            if(tree[now].r!=-1)q.push(tree[now].r);
        }
        cout << s << endl;
    }
    return 0;
}
