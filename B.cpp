#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <functional>
using namespace std;

typedef long long LL;
const int MAXN = 5e5 + 10;
const int MOD = 1e9 + 7;

int n, m, sz, x, tot, caseNum = 0;
int values[MAXN], first[MAXN], nextNode[MAXN], root[MAXN], parent[MAXN];
char inputStr[10];

void addEdge(int x, int y) {
    values[sz] = y;
    nextNode[sz] = first[x];
    first[x] = sz++;
}

int findRoot(int x) {
    return x == parent[x] ? x : parent[x] = findRoot(parent[x]);
}

struct Point {
    int x, y, z;
    void read() { scanf("%d%d", &x, &y); }
} points[MAXN], queries[MAXN];

struct SplayTree {
    const static int MAXN = 5e5 + 10;
    const static int INF = 0x7FFFFFFF;
    int ch[MAXN][2], F[MAXN], sz;
    int A[MAXN], C[MAXN], S[MAXN], current;

    int createNode(int f, int a, int s) { 
        S[sz] = C[sz] = s; 
        A[sz] = a; 
        ch[sz][0] = ch[sz][1] = 0; 
        F[sz] = f; 
        return sz++; 
    }

    void clear() { 
        sz = 1; 
        ch[0][0] = ch[0][1] = F[0] = 0; 
        S[0] = C[0] = 0; 
    }

    void rotate(int x, int k) {
        int y = F[x]; 
        ch[y][!k] = ch[x][k]; 
        F[ch[x][k]] = y;
        if (F[y]) ch[F[y]][y == ch[F[y]][1]] = x;
        F[x] = F[y]; F[y] = x; ch[x][k] = y;
        C[x] = C[y]; C[y] = C[ch[y][0]] + C[ch[y][1]] + S[y];
    }

    void splay(int x, int root) {
        while (F[x] != root) {
            if (F[F[x]] == root) {
                rotate(x, x == ch[F[x]][0]); 
                return;
            }
            int y = x == ch[F[x]][0], z = F[x] == ch[F[F[x]]][0];
            y ^ z ? (rotate(x, y), rotate(x, z)) : (rotate(F[x], z), rotate(x, y));
        }
    }

    int build(int v) { return createNode(0, v, 1); }

    int findKth(int x, int k) {
        int fx = findRoot(x), rx = root[fx];
        splay(rx, 0);
        if (C[rx] < k || k <= 0) return 0;
        k = C[rx] + 1 - k;
        for (int i = rx; i;) {
            if (C[ch[i][0]] >= k) { i = ch[i][0]; continue; }
            if (C[ch[i][0]] + S[i] >= k) return A[i];
            k -= C[ch[i][0]] + S[i]; i = ch[i][1];
        }
    }

    void insertNode(int x) {
        F[x] = ch[x][0] = ch[x][1] = 0; C[x] = S[x];
        for (int i = current; i; i = ch[i][A[x] > A[i]]) {
            C[i] += S[x];
            if (A[x] == A[i]) { S[i] += S[x]; splay(i, 0); current = i; return; }
            if (!ch[i][A[x] > A[i]]) {
                ch[i][A[x] > A[i]] = x; F[x] = i; splay(x, 0); current = x; return;
            }
        }
    }

    void dfs(int x) {
        if (!x) return;
        dfs(ch[x][0]);
        dfs(ch[x][1]);
        insertNode(x);
    }

    void mergeTrees(int x, int y) {
        int fx = findRoot(x), fy = findRoot(y);
        if (fx == fy) return;
        int rx = root[fx], ry = root[fy];
        splay(rx, 0); splay(ry, 0);
        if (C[rx] > C[ry]) swap(rx, ry), swap(fx, fy);
        parent[fx] = fy; current = ry; dfs(rx); root[fy] = current;
    }

    void changeNode(int x, int y, int z) {
        int fx = findRoot(x), rx = root[fx], newNode = createNode(0, z, 1);
        splay(rx, 0); current = rx; insertNode(newNode);
        for (int i = current; i; i = ch[i][y > A[i]]) 
            if (A[i] == y) { splay(i, 0); current = i; break; }
        if (S[current] > 1) { S[current]--; C[current]--; return; }
        if (!ch[current][0] || !ch[current][1]) {
            current = ch[current][0] + ch[current][1]; 
            F[current] = 0; root[fx] = current; 
            return;
        }
        for (int i = ch[current][0]; i; i = ch[i][1]) if (!ch[i][1]) { splay(i, 0); current = i; break; }
        int temp = ch[current][1]; ch[current][1] = ch[temp][1]; F[ch[current][1]] = current; C[current]--; root[fx] = current;
    }
} solve;

int main() {
    while (scanf("%d%d", &n, &m) != EOF, n + m) {
        sz = 0; solve.clear();
        for (int i = 1; i <= n; i++) {
            scanf("%d", &x); 
            first[i] = -1; 
            addEdge(i, x); 
            parent[i] = i;
        }

        for (int i = 1; i <= m; i++) points[i].read(), points[i].z = 1;
        
        for (tot = 0; scanf("%s", inputStr), inputStr[0] != 'E'; tot++) {
            queries[tot].z = (inputStr[0] == 'D' ? 0 : (inputStr[0] == 'Q' ? 1 : 2));
            if (!queries[tot].z) {
                scanf("%d", &queries[tot].x);
                points[queries[tot].x].z = 0;
            } else {
                queries[tot].read();
                if (queries[tot].z == 2) addEdge(queries[tot].x, queries[tot].y);
            }
        }

        for (int i = 1; i <= n; i++) root[i] = solve.build(values[first[i]]);
        for (int i = 1; i <= m; i++) if (points[i].z) solve.mergeTrees(points[i].x, points[i].y);
        
        double ans = 0; 
        int div = 0;
        
        for (int i = tot - 1; i >= 0; i--) {
            if (!queries[i].z) solve.mergeTrees(points[queries[i].x].x, points[queries[i].x].y);
            else {
                if (queries[i].z == 1) ans += solve.findKth(queries[i].x, queries[i].y), div++;
                else {
                    first[queries[i].x] = nextNode[first[queries[i].x]];
                    solve.changeNode(queries[i].x, queries[i].y, values[first[queries[i].x]]);
                }
            }
        }

        printf("Case %d: %.6f\n", ++caseNum, ans / div);
    }

    return 0;
}
