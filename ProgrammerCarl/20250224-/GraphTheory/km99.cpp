#include <bits/stdc++.h>

using namespace std;

int result = 0;

vector<vector<int>> dic = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1}
};

bool isValid(int x, int y, int N, int M) {
    if (x >= N || x < 0 || y < 0 || y >= M) {
        return false;
    }
    return true;
}

void dfs(vector<vector<int>> &graph, vector<vector<bool>> &visited, int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nextX = x + dic[i][0];
        int nextY = y + dic[i][1];
        if (isValid(nextX, nextY, graph.size(), graph[0].size()) && !visited[nextX][nextY] && graph[nextX][nextY]) {
            visited[nextX][nextY] = true;
            dfs(graph, visited, nextX, nextY);
        }
    }
}

int main(void) {
    int N;
    int M;
    cin >> N >> M;
    vector<vector<int>> graph(N, vector<int>(M, 0));
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j] && graph[i][j]) {
                result++;
                visited[i][j] = true;
                dfs(graph, visited, i, j);
            }
        }
    }

    cout << result << endl;
}