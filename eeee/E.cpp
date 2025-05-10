#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> deg(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> deg[i];
        sum += deg[i];
    }
    if (sum % 2) {
        cout << "None\n";
        return 0;
    }
    vector<vector<int>> adj(n, vector<int>(n, 0));
    vector<pair<int,int>> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = {deg[i], i};
    }
    for (int round = 0; round < n; round++) {
        sort(v.begin() + round, v.end(), [&](auto &a, auto &b) {
            return a.first > b.first;
        });
        int d = v[round].first;
        int u = v[round].second;
        if (d < 0 || d > n - 1 - round) {
            cout << "None\n";
            return 0;
        }
        for (int k = 1; k <= d; k++) {
            int vi = v[round + k].second;
            if (v[round + k].first <= 0) {
                cout << "None\n";
                return 0;
            }
            adj[u][vi] = adj[vi][u] = 1;
            v[round + k].first--;
        }
        v[round].first = 0;
    }
    for (int i = 0; i < n; i++) {
        if (v[i].first != 0) {
            cout << "None\n";
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adj[i][j] << (j + 1 < n ? ' ' : '\n');
        }
    }
    return 0;
}
