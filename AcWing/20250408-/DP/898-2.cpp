#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> dp[i][j];
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            dp[i][j] += max(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j <= i; j++) {
    //         cout << dp[i][j] << ' ';

    //     }
    //     cout << endl;
    // }

    cout << dp[0][0] << endl;
    return 0;
}
