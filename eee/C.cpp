#include <bits/stdc++.h>
using namespace std;

struct Node {
    int ki;
    vector<int> adj;
};

int main() {
    int n;
    cin >> n;
    vector<Node> nodes(n);
    for (int i = 0; i < n; ++i) {
        int ki, m;
        cin >> ki >> m;
        vector<int> adj(m);
        for (int j = 0; j < m; ++j) {
            cin >> adj[j];
        }
        nodes[i] = {ki, adj};
    }

    if (n == 1) {
        cout << "Yes" << endl;
        return 0;
    }

    vector<vector<int>> adj_forward(n + 1);
    for (int u = 1; u <= n; ++u) {
        for (int v : nodes[u - 1].adj) {
            adj_forward[u].push_back(v);
        }
    }

    vector<vector<int>> adj_backward(n + 1);
    for (int u = 1; u <= n; ++u) {
        for (int v : adj_forward[u]) {
            adj_backward[v].push_back(u);
        }
    }

    bool in_reachable_from_start[101] = {false};
    queue<int> q;
    q.push(1);
    in_reachable_from_start[1] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj_forward[u]) {
            if (!in_reachable_from_start[v]) {
                in_reachable_from_start[v] = true;
                q.push(v);
            }
        }
    }

    bool in_can_reach_end[101] = {false};
    queue<int> q2;
    q2.push(n);
    in_can_reach_end[n] = true;
    while (!q2.empty()) {
        int v = q2.front();
        q2.pop();
        for (int u : adj_backward[v]) {
            if (!in_can_reach_end[u]) {
                in_can_reach_end[u] = true;
                q2.push(u);
            }
        }
    }

    vector<pair<int, int>> edges;
    for (int u = 1; u <= n; ++u) {
        if (in_reachable_from_start[u] && in_can_reach_end[u]) {
            for (int v : nodes[u - 1].adj) {
                if (in_can_reach_end[v]) {
                    edges.emplace_back(u, v);
                }
            }
        }
    }

    int initial = 100 + nodes[0].ki;
    if (initial <= 0) {
        cout << "No" << endl;
        return 0;
    }

    vector<int> max_energy(n + 1, INT_MIN);
    max_energy[1] = initial;

    for (int i = 0; i < n; ++i) {
        bool updated = false;
        for (auto& e : edges) {
            int u = e.first, v = e.second;
            if (max_energy[u] > 0) {
                int new_energy = max_energy[u] + nodes[v - 1].ki;
                if (new_energy > max_energy[v] && new_energy > 0) {
                    max_energy[v] = new_energy;
                    updated = true;
                }
            }
        }
        if (!updated) break;
    }

    bool has_positive_cycle = false;
    for (auto& e : edges) {
        int u = e.first, v = e.second;
        if (max_energy[u] > 0) {
            int new_energy = max_energy[u] + nodes[v - 1].ki;
            if (new_energy > max_energy[v] && new_energy > 0) {
                has_positive_cycle = true;
                break;
            }
        }
    }

    if (has_positive_cycle) {
        cout << "Yes" << endl;
        return 0;
    }

    if (max_energy[n] > 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}