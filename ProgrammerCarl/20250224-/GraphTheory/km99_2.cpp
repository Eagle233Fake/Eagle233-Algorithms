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

void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int row, int col) {
    if (!isValid(row, col, grid) || visited[row][col] || !grid[row][col]) {
        return;
    }
    visited[row][col] = true;

    for (int i = 0; i < 4; i++) {
        int nextRow = row + dic[i][0];
        int nextCol = col + dic[i][1];
        dfs(grid, visited, nextRow, nextCol);
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
                dfs(grid, visited, i, j);
            }
        }
    }

    cout << result << endl;
}