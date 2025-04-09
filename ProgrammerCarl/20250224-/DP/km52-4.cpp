#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n, v;
    cin >> n >> v;
    vector<int> w(n);
    vector<int> val(n);

    for (int i = 0; i < n; i++) {
        cin >> w[i] >> val[i];
    }

    vector<vector<int>> dp(n, vector<int>(v + 1, 0));

    for (int j = w[0]; j <= v; j++) {
        dp[0][j] = dp[0][j - w[0]] + val[0];
    }

    for (int j = 0; j <= v; j++) {
        for (int i = 1; i < n; i++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= w[i]) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - w[i]] + val[i]);
            }
        }
    }

    cout << dp[n - 1][v] << endl;
}