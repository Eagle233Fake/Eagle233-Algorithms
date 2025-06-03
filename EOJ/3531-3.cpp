#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n, k;
    cin >> n >> k;
    vector<bool> isBroken(n + 1, false);
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        isBroken[x] = true;
    }

    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= 3; i++) {
            if (j >= i && !isBroken[j]) {
                dp[j] += dp[j - i];
            }
        }
    }

    cout << dp[n] << endl;
}