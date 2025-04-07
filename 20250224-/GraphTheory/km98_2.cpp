#include <bits/stdc++.h>

using namespace std;

vector<int> path;
vector<vector<int>> result;

void dfs(vector<list<int>> &graph, int s, int N) {
    if (s == N) {
        result.push_back(path);
        return;
    }

    for (int i : graph[s]) {
        path.push_back(i);
        dfs(graph, i, N);
        path.pop_back();
    }
}

int main(void) {
    int N, M;
    cin >> N >> M;

    vector<list<int>> graph(N + 1);

    for (int i = 0; i < M; i++) {
        int s, t;
        cin >> s >> t;
        graph[s].push_back(t);
    }

    path.push_back(1);
    dfs(graph, 1, N);

    if (result.empty()) {
        cout << -1 << endl;
    }

    for (vector<int> v : result) {
        for (int i = 0; i < v.size() - 1; i++) {
            cout << v[i] << " ";
        }
        cout << v[v.size() - 1] << endl;
    }
}