#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;

    vector<bool> isBroken(n + 1, false);
    for (int i = 0; i < k; i++) {
        int index;
        cin >> index;
        isBroken[index] = true;
    }

    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int j = 0; j <= n; j++) {
        for (int i = 1; i <= 3; i++) {
            if (j >= i && !isBroken[j]) {
                dp[j] += dp[j - i];
            }
        }
    }

    cout << dp[n];
    return 0;
}
