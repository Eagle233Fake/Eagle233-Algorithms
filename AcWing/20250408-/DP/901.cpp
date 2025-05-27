#include <bits/stdc++.h>

using namespace std;

int R, C;

int dx[4] = {
    0, 1, 0, -1
};
int dy[4] = {
    1, 0, -1, 0
};

int dp(int x, int y, vector<vector<int>> &f, vector<vector<int>> &grid) {
    if (f[x][y] != -1) {
        return f[x][y];
    }

    f[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int a = x + dx[i];
        int b = y + dy[i];
        if (a <= R && a >= 1 && b <= C && b >= 1 && grid[a][b] < grid[x][y]) {
            f[x][y] = max(f[x][y], dp(a, b, f, grid) + 1);
        }
    }

    return f[x][y];
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C;

    vector<vector<int>> grid(R + 1, vector<int>(C + 1, 0));
    vector<vector<int>> f(R + 1, vector<int>(C + 1, -1));

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = 0;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            ans = max(ans, dp(i, j, f, grid));
        }
    }

    cout << ans << endl;
    return 0;
}
