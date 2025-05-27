#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n), adj_t(n);
    for (int i = 0; i < n; ++i) {
        int j;
        while (cin >> j && j != 0) {
            j--; // 转换为0-based索引
            adj[i].push_back(j);
            adj_t[j].push_back(i);
        }
    }

    vector<bool> visited(n, false);
    vector<int> order;
    function<void(int)> dfs1 = [&](int u) {
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v]) {
                dfs1(v);
            }
        }
        order.push_back(u);
    };

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs1(i);
        }
    }

    reverse(order.begin(), order.end());

    vector<int> component(n, -1);
    int current_component = 0;
    visited.assign(n, false);
    function<void(int)> dfs2 = [&](int u) {
        visited[u] = true;
        component[u] = current_component;
        for (int v : adj_t[u]) {
            if (!visited[v]) {
                dfs2(v);
            }
        }
    };

    for (int u : order) {
        if (!visited[u]) {
            dfs2(u);
            current_component++;
        }
    }

    int k = current_component;
    vector<int> indegree(k, 0), outdegree(k, 0);
    vector<vector<bool>> added(k, vector<bool>(k, false));

    for (int u = 0; u < n; ++u) {
        for (int v : adj[u]) {
            if (component[u] != component[v]) {
                int cu = component[u];
                int cv = component[v];
                if (!added[cu][cv]) {
                    added[cu][cv] = true;
                    outdegree[cu]++;
                    indegree[cv]++;
                }
            }
        }
    }

    int c1 = 0, c2 = 0;
    for (int i = 0; i < k; ++i) {
        if (indegree[i] == 0) c1++;
        if (outdegree[i] == 0) c2++;
    }

    int ans1 = c1;
    int ans2 = (k == 1) ? 0 : max(c1, c2);

    cout << ans1 << endl;
    cout << ans2 << endl;

    return 0;
}
