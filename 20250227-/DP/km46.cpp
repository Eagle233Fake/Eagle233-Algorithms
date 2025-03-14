#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int m, n;
    cin >> m >> n;
    
    int weight[m + 1] = {0};
    for (int i = 1; i <= m; i++) {
        cin >> weight[i];
    }
    
    int value[m + 1] = {0};
    for (int i = 1; i <= m; i++) {
        cin >> value[i];
    }
    
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i < m + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            if (j < weight[i]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
    }
    
    cout << dp[m][n] << endl;
}