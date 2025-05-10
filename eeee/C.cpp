#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj_matrix(n, vector<int>(n, 0));
    
    for (int k = 0; k < m; ++k) {
        int type, u, v;
        cin >> type >> u >> v;
        if (type == 0) {
            adj_matrix[u][v] = 1;
        } else { 
            adj_matrix[u][v] = 1;
            adj_matrix[v][u] = 1;
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << adj_matrix[i][j] << (j == n - 1 ? "" : " ");
        }
        cout << "\n";
    }
    
    return 0;
}