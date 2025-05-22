#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    dp[0][0] = 1;

    // do[i][j] = max(dp[i - 1][j - 1], dp[i - j][j])
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - j][j]) % mod;
        }
    }

    int res = 0;

    for (int j = 0; j <= n; j++) {
        res = (res + dp[n][j]) % mod;
    }

    cout << res << endl;

    return 0;
}
