#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> result;
vector<int> path;

void dfs(int s, int N, vector<vector<bool>> &graph) {
    if (s == N) {
        result.push_back(path);
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (graph[s][i]) {
            path.push_back(i);
            dfs(i, N, graph);
            path.pop_back();
        }
    }
}

int main(void) {
    int N, M;
    cin >> N >> M;

    vector<vector<bool>> graph(N + 1, vector<bool>(N + 1, false));
    for (int i = 0; i < M; i++) {
        int s, t;
        cin >> s >> t;
        graph[s][t] = true;
    }

    path.push_back(1);
    dfs(1, N, graph);

    if (result.empty()) {
        cout << -1 << endl;
        return 0;
    }

    for (vector<int> v : result) {
        for (int i = 0; i < v.size(); i++) {
            if (i == 0) {
                cout << v[0];
            } else {
                cout << " " << v[i];
            }
         }
         cout << endl;
    }
}