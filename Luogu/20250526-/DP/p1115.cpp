#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     
    int n;
    cin >> n;
    vector<int> nums(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    vector<int> dp(n + 1, 0);

    int ans = -1e6;
    for (int i = 1; i < nums.size(); i++) {
        dp[i] = max(nums[i], dp[i - 1] + nums[i]);
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;
    return 0;
}
