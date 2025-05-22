#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    int ans = 0;
    vector<vector<int>> dp(n + 1, vector<int>(71, 0));
    
    for (int i = 1; i <= n; i++) {
        dp[i][a[i]] = 1;
        ans = max(ans, a[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 70; j++) {
            if (dp[i][j]) {
                int mid = i + dp[i][j];
                if (mid <= n && dp[mid][j]) {
                    dp[i][j + 1] = dp[i][j] + dp[mid][j];
                    ans = max(ans, j + 1);
                }
            }
        }
    }
    
    cout << ans << endl;
    
    
}