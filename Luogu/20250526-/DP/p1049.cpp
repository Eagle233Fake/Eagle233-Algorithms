#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int W, n;
    cin >> W >> n;
    vector<int> w(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    vector<int> dp(W + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = W; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + w[i]);
        }
    }

    cout << W - dp[W] << endl;
    return 0;
}
