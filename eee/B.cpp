#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAXN = 10001;
const int MAXLOG = 15;

vector<int> adj[MAXN];
int parent[MAXN];
int depth[MAXN];
int ancestor[MAXN][MAXLOG];

void dfs(int node, int par, int dep) {
    parent[node] = par;
    depth[node] = dep;
    for (int i = 0; i < adj[node].size(); ++i) {
        int child = adj[node][i];
        if (child != par) {
            dfs(child, node, dep + 1);
        }
    }
}

void binaryLift(int N) {
    for (int i = 1; i <= N; ++i) {
        ancestor[i][0] = parent[i];
    }
    
    for (int j = 1; (1 << j) <= N; ++j) {
        for (int i = 1; i <= N; ++i) {
            if (ancestor[i][j - 1] != -1) {
                ancestor[i][j] = ancestor[ancestor[i][j - 1]][j - 1];
            }
        }
    }
}

int findLCA(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    
    int log;
    for (log = 1; (1 << log) <= depth[u]; ++log);
    log--;
    
    for (int i = log; i >= 0; --i) {
        if (depth[u] - (1 << i) >= depth[v]) {
            u = ancestor[u][i];
        }
    }
    
    if (u == v) return u;
    
    for (int i = log; i >= 0; --i) {
        if (ancestor[u][i] != -1 && ancestor[u][i] != ancestor[v][i]) {
            u = ancestor[u][i];
            v = ancestor[v][i];
        }
    }
    
    return parent[u];
}

int main() {
    int N, M, S;
    cin >> N >> M >> S;
    
    for (int i = 1; i <= N; ++i) {
        adj[i].clear();
        parent[i] = -1;
        depth[i] = 0;
        for (int j = 0; j < MAXLOG; ++j) {
            ancestor[i][j] = -1;
        }
    }
    
    for (int i = 1; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    dfs(S, -1, 0);
    binaryLift(N);
    
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        int lca = findLCA(a, b);
        cout << lca << endl;
    }
    
    return 0;
}
