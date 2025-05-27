#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> adj[i][j];
        }
    }

    vector<int> lowcost(n);
    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
        lowcost[i] = adj[0][i];
    }
    visited[0] = true;
    int sum = 0;

    for (int cnt = 1; cnt < n; ++cnt) {
        int min_val = INT_MAX;
        int min_idx = -1;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && lowcost[j] < min_val) {
                min_val = lowcost[j];
                min_idx = j;
            }
        }
        if (min_idx == -1) {
            break;
        }
        sum += min_val;
        visited[min_idx] = true;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && adj[min_idx][j] < lowcost[j]) {
                lowcost[j] = adj[min_idx][j];
            }
        }
    }

    cout << sum << endl;

    return 0;
}