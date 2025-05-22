#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    
    vector<vector<ull>> dp(35, vector<ull>(35, 0));

    for (int i = 1; i <= 34; i++) {
        dp[i][i] = 1;
    }

    // i - j - 1
    // dp[i][j] = 2 * dp[i - 1][j] + ((1 << (i - j - 1)) - dp[i - j - 1][j])
    for (int i = 1; i <= 34; i++) {
        for (int j = 0; j < i; j++) {
            dp[i][j] = 2 * dp[i - 1][j];
            if (i >= j + 1) {
                dp[i][j] += (1ULL << (i - j - 1)) - dp[i - j - 1][j];
            }
        }
    }

    // for (int i = 0; i <= 10; i++) {
    //     for (int j = 0; j <= i; j++) {
    //         cout << dp[i][j] << ' ';
    //     }

    //     cout << endl;
    // }

    while (cin >> n >> m) {
        if (n == -1) {
            return 0;
        }
        cout << dp[n][m] << endl;
    }
    
    return 0;
}
