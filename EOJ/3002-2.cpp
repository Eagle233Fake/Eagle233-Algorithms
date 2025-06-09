#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

int main(void) {
    vector<ull> dp(80, 0);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    for (int i = 3; i < 80; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "case #" << i << ':' << endl;
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }

    return 0;
}