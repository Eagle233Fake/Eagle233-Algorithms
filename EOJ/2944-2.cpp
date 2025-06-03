#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i < 5; i++) {
            for (int j = i; j <= n; j++) {
                dp[j] += dp[j - i];
            }
        }

        cout << dp[n] << endl;
    }
}