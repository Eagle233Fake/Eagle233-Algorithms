#include <bits/stdc++.h>

using namespace std;

int r = 0;

vector<vector<int>> dic = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};

bool isValid(vector<vector<int>> &grid, int i, int j) {
    if (i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0) {
        return false;
    }
    return true;
}

void bfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j) {
    queue<pair<int, int>> que;
    que.push(pair<int, int>(i, j));
    visited[i][j] = 1;

    while (!que.empty()) {
        pair<int, int> p = que.front();
        que.pop();
        for (int k = 0; k < 4; k++) {
            int i2 = p.first + dic[k][0];
            int j2 = p.second + dic[k][1];
            if (isValid(grid, i2, j2) && grid[i2][j2] && !visited[i2][j2]) {
                que.push(pair<int, int>(i2, j2));
                visited[i2][j2] = 1;
                r++;
            }
        }
    }
}

int main(void) {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> grid(N, vector<int>(M));
    vector<vector<bool>> visited(N, vector<bool>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    int result = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j] && grid[i][j]) {
                r = 1;
                bfs(grid, visited, i, j);
                result = max(result, r);
            }
        }
    }

    cout << result << endl;
}