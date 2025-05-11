#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;

    vector<bool> broken(n + 1, false);
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        broken[x] = true;
    }

    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    if (!broken[1]) {
        dp[1] = 1;
    }
    if (!broken[2]) {
        dp[2] = dp[1] + 1;
    }

    for (int i = 3; i <= n; i++) {
        if (!broken[i]) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
    }

    cout << dp[n] << endl;
    return 0;
}
