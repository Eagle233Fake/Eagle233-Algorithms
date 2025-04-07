#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dic = {
    {1, 0}, 
    {0, 1},
    {-1, 0},
    {0, -1}
};

bool isValid(int row, int col, vector<vector<int>> &grid) {
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) {
        return false;
    }
    return true;
}

void bfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int row, int col) {
    queue<pair<int, int>> que;
    que.push({row, col});
    visited[row][col] = true; // 进队列就标记
    while (!que.empty()) {
        pair<int, int> cur = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int nextRow = cur.first + dic[i][0];
            int nextCol = cur.second + dic[i][1];
            if (isValid(nextRow, nextCol, grid) && !visited[nextRow][nextCol] && grid[nextRow][nextCol]) {
                que.push(pair<int, int>({nextRow, nextCol}));
                visited[nextRow][nextCol] = true; // 进队列就标记
            }
        }
    }
}

int main(void) {
    int N, M;
    cin >> N >> M;
    int result = 0;
    vector<vector<int>> grid(N, vector<int>(M));
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j] && grid[i][j]) {
                result++;
                bfs(grid, visited, i, j);
            }
        }
    }

    cout << result;
}