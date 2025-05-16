#include <bits/stdc++.h>

using namespace std;

int mod = 1e9 + 7;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            dp[j] = (dp[j] + dp[j - i]) % mod;
        }
    }

    cout << dp[n] << endl;
    return 0;
}
