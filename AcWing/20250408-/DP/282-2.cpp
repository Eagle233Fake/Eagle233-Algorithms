#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<int> s(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        cin >> s[i];
    }

    for (int i = 1; i <= N; i++) {
        s[i] += s[i - 1];
    }

    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));

    // dp[i][j] = dp[i][k] + dp[k + 1][j] + s[j] - s[i - 1];

    for (int len = 2; len <= N; len++) {
        for (int i = 1; i + len - 1 <= N; i++) {
            int j = i + len - 1;
            dp[i][j] = 1e8;
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + s[j] - s[i - 1]);
            }
        }
    }

    cout << dp[1][N] << endl;
    return 0;
}
