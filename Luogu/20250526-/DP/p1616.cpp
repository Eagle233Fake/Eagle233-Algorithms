#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t, n;
    cin >> t >> n;

    vector<int> w(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }

    vector<ull> dp(t + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = w[i]; j <= t; j++) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }

    cout << dp[t] << endl;
    return 0;
}
