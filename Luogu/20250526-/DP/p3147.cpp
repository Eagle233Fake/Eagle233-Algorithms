#include <bits/stdc++.h>

using namespace std;

const int N = 270000;
const int M = 60;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<vector<int>> dp(M, vector<int>(N, 0));
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        dp[x][i] = i;
    }

    // dp[i][j] = dp[i - 1][dp[i - 1][j] + 1];
    int ans = 0;
    for (int i = 2; i < M; i++) {
        for (int j = 1; j <= n; j++) {
            int mid = dp[i - 1][j];

            if (mid > 0 && mid < n) {
                if (dp[i - 1][mid + 1]) {
                    dp[i][j] = dp[i - 1][mid + 1];
                    ans = max(ans, i);
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
