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

void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j) {
    if (!isValid(grid, i, j) || visited[i][j] || !grid[i][j]) {
        return;
    }

    r++;
    visited[i][j] = true;

    for (int k = 0; k < 4; k++) {
        int i2 = i + dic[k][0];
        int j2 = j + dic[k][1];
        dfs(grid, visited, i2, j2);
    }
}

int main(void) {
    c

    int result = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] && !visited[i][j]) {
                r = 0;
                dfs(grid, visited, i, j);
                result = max(r, result);
            }
        }
    }

    cout << result << endl;
}