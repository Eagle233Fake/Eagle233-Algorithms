#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dic = {
    {1, 0}, 
    {-1, 0},
    {0, 1},
    {0, -1}
};

bool isValid(int i, int j, vector<vector<int>> &grid) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
        return false;
    }
    return true;
}

void bfs(vector<vector<int>> &grid, int i, int j) {
    queue<pair<int, int>> que;
    que.push({i, j});
    grid[i][j] = 0;
    while (!que.empty()) {
        pair<int, int> p = que.front();
        que.pop();
        for (int k = 0; k < 4; k++) {
            int nextI = p.first + dic[k][0];
            int nextJ = p.second + dic[k][1];
            if (isValid(nextI, nextJ, grid) && grid[nextI][nextJ]) {
                que.push({nextI, nextJ});
                grid[nextI][nextJ] = 0;
            }
        }
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
            bfs(grid, i, 0);
        }
        if (grid[i][M - 1]) {
            bfs(grid, i, M - 1);
        }
    }

    for (int j = 0; j < M; j++) {
        if (grid[0][j]) {
            bfs(grid, 0, j);
        }
        if (grid[N - 1][j]) {
            bfs(grid, N - 1, j);
        }
    }

    int result = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j]) {
                result++;
            }
        }
    }

    cout << result << endl;
}