#include <bits/stdc++.h>

using namespace std;

void solve(void) {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> dp(n + 1, 0);
    // dp[i] = max(dp[j] + a[i], dp[i]);
    
    int res = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = a[i];
        for (int j = 1; j < i; j++) {
            if (a[i] > a[j]) {
                dp[i] = max(dp[j] + a[i], dp[i]);
            }
        }
        res = max(dp[i], res);
    }

    cout << res << endl;
}

int main(void) {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cout << "case #" << i << ':' << endl;
        solve();
    }
}