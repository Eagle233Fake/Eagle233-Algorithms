#include <bits/stdc++.h>

using namespace std;

int main(void) {
    string A, B;
    cin >> A >> B;
    vector<int> dp(B.size() + 1, 0);

    int res = 0;
    for (int i = 1; i <= A.size(); i++) {
        for (int j = B.size(); j >= 1; j--) {
            if (A[i - 1] == B[j - 1]) {
                // dp[i][j] = dp[i - 1][j - 1] + 1;
                dp[j] = dp[j - 1] + 1;
            } else {
                dp[j] = 0;
            }
            res = max(res, dp[j]);
        }
    }

    cout << res << endl;
}