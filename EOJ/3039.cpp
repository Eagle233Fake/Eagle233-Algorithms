#include <bits/stdc++.h>

using namespace std;

void solve(void) {
    int n, m;
    cin >> n >> m;

    vector<int> dp(n + 1, 0);

    dp[0] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = n; j >= i; j--) {
            dp[j] += dp[j - i];
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