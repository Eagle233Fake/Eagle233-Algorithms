#include <bits/stdc++.h>

using namespace std;

int dx[4] = {
    0, 1, -1, 0
};
int dy[4] = {
    1, 0, 0, -1
};

int dp(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &f) {
    if (f[r][c] != -1) {
        return f[r][c];
    }

    f[r][c] = 1;

    for (int i = 0; i < 4; i++) {
        int a = r + dx[i];
        int b = c + dy[i];

        if (a >= 1 && a <= grid.size() - 1 && b >= 1 && b <= grid[0].size() - 1 && grid[a][b] < grid[r][c]) {
            f[r][c] = max(f[r][c], dp(a, b, grid, f) + 1);
        }
    }

    return f[r][c];
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;  
    vector<vector<int>> grid(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> f(n + 1, vector<int>(m + 1, -1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans = max(ans, dp(i, j, grid, f));
        }
    }

    cout << ans << endl;
    return 0;
}
