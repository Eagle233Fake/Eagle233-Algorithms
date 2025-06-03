#include <bits/stdc++.h>

using namespace std;

int main(void) {
    vector<unsigned long long> dp(75, 0);
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= 74; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cout << "case #" << i << ':' << endl;
        int t;
        cin >> t;
        cout << dp[t] << endl;
    }

    return 0;
}