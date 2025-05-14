#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<unsigned long long>> dp(32, vector<unsigned long long>(32, 0));
    for (int i = 0; i < 32; i++) {
        dp[i][i] = 1;
    }

    for (int i = 1; i <= 31; i++) {
        for (int j = 0; j < i; j++) {   // i - 1 - (j - 1) - 1 == i - j - 1
            dp[i][j] = 2 * dp[i - 1][j];
            dp[i][j] += (1ULL << (i - j - 1)) - dp[i - j - 1][j];
        }
    }

    // for (int i = 0; i < 32; i++) {
    //     for (int j = 0; j < 32; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    int n, m;
    while (cin >> n >> m) {
        if (n == -1 && m == -1) {
            return 0;
        }
        cout << dp[n][m] << endl;
    }
    return 0;
}
