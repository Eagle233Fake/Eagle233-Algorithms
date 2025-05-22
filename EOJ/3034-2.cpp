#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9;

void solve(void) {
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i *= 2) {
        for (int j = i; j <= n; j++) {
            dp[j] = (dp[j] + dp[j - i]) % mod;
        }
    }

    cout << dp[n];
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cout << "case #" << i << ':' << endl;
        solve();
        cout << endl;
    }

    return 0;
}