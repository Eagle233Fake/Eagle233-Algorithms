#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve(void) {
    int n;
    cin >> n;

    vector<ll> nums(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin() + 1, nums.end());

    ll mmax = nums[n];
    ll mmin = nums[1];
    ll bias = mmax - mmin;

    // i: 选取第i个元素
    // j: 公差d
    // k: 选取的数的值 - mmin
    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(bias + 1, vector<ll>(mmax + 1, 0)));

    for (int j = 0; j <= bias; j++) {
        dp[1][j][mmin] = 1;
    }
    
    for (int i =  1; i <= n; i++) {
        for (int j = 0; j <= bias; j++) {
            ll preVal = nums[i] - j;

            if (preVal >= mmin && preVal <= mmax) {
                if (dp[i - 1][j][preVal] > 0) {
                    dp[i][j][nums[i]] = dp[i - 1][j][preVal] + 1;
                }
            }
        }
    }

    mmax = INT_MIN;

    for (int j = 0; j <= bias; j++) {
        for (int k = 0; k <= bias; k++) {
            mmax = max(mmax, dp[n][j][k]);
        }
    }

    cout << mmax;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cout << "case #" << i << ':' << endl;
        solve();
        cout << endl;
    }

    return 0;
}