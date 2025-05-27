#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    vector<int> dp(m + 1, 0);
    dp[0] = 1;

    for (auto i : w) {
        for (int j = m; j >= i; j--) {
            dp[j] += dp[j - i];
        }
    }

    cout << dp[m] << endl;
    return 0;
}
