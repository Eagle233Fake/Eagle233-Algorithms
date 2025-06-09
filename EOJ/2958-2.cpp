#include <bits/stdc++.h>

using namespace std;

void solve(void) {
    int n;
    cin >> n;
    vector<int> nums(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }

    vector<int> dp(n + 1, 0);

    int res = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = nums[i];
        for (int j = 1; j <= i; j++) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + nums[i]);
            }
        }
        res = max(res, dp[i]);
    }

    cout << res << endl;

}

int main(void) {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "case #" << i << ':' << endl;
        solve();
    }
}