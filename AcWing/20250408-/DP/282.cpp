#include <bits/stdc++.h>

using namespace std;

const int N = 305;

int s[N];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    for (int i = 1; i <= n; i++) {
        s[i] += s[i - 1];
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len <= n + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = 10000000;
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + s[j] - s[i - 1]);
            }
        }
    }

    cout << dp[1][n] << endl;
    return 0;
}
