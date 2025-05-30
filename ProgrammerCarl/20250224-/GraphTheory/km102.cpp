#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dic = {
    {0, 1}, 
    {1, 0},
    {-1, 0},
    {0, -1}
};

bool isValid(vector<vector<int>> &grid, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
        return false;
    }
    return true;
}

void dfs(vector<vector<int>> &grid, int i, int j) {
    if (!isValid(grid, i, j) || !grid[i][j] || grid[i][j] == 2) {
        return;
    }

    grid[i][j] = 2;

    for (int k = 0; k < 4; k++) {
        int nextI = i + dic[k][0];
        int nextJ = j + dic[k][1];

        dfs(grid, nextI, nextJ);
    }
}

int main(void) {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> grid(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        if (grid[i][0]) {
            dfs(grid, i, 0);
        }
        if (grid[i][M - 1]) {
            dfs(grid, i, M - 1);
        }
    }

    for (int j = 0; j < M; j++) {
        if (grid[0][j]) {
            dfs(grid, 0, j);
        }
        if (grid[N - 1][j]) {
            dfs(grid, N - 1, j);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == 2) {
                cout << "1 ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}