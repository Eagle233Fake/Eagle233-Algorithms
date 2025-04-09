#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dic = {
    {0, 1},
    {1, 0}, 
    {-1, 0}, 
    {0, -1}
};

bool isValid(vector<vector<int>> &grid, int row, int col) {
    if (row >= grid.size() || row < 0 || col < 0 || col >= grid[0].size()) {
        return false;
    }
    return true;
}

void bfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int row, int col) {
    queue<pair<int, int>> que;
    que.push(pair<int, int>(row, col));
    visited[row][col] = true;
    while (!que.empty()) {
        pair<int, int> p = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int nextRow = p.first + dic[i][0];
            int nextCol = p.second + dic[i][1];
            if (isValid(grid, nextRow, nextCol) && grid[nextRow][nextCol] && !visited[nextRow][nextCol]) {
                que.push(pair<int, int>(nextRow, nextCol));
                visited[nextRow][nextCol] = true;
            }
        }
    }
}

int main(void) {
    int N;
    int M;
    cin >> N >> M;
    vector<vector<int>> grid(N, vector<int>(M, 0));
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    int result = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j] && grid[i][j]) {
                result++;
                bfs(grid, visited, i, j);
            }
        }
    }

    cout << result << endl;
}