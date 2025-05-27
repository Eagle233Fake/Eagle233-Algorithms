#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;

vector<int> adj[MAXN];
int degree[MAXN];     
bool visited[MAXN];   

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
}

bool isConnected(int N) {
    memset(visited, false, sizeof(visited));
    int start = -1;
    for (int i = 1; i <= N; ++i) {
        if (degree[i] > 0) {
            start = i;
            break;
        }
    }
    if (start == -1) return true; 
    dfs(start);
    
    for (int i = 1; i <= N; ++i) {
        if (degree[i] > 0 && !visited[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int N, M;
    cin >> N >> M;
    
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }
    
    if (!isConnected(N)) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 1; i <= N; ++i) {
        if (degree[i] % 2 != 0) {
            cout << 0 << endl;
            return 0;
        }
    }

    cout << 1 << endl;
    
    return 0;
}
