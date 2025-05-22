#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, W;
    cin >> N >> W;

    vector<int> dp(W + 1, 0);

    for (int i = 1; i <= N; i++) {
        int n;
        cin >> n;

        vector<int> w(n + 1, 0);
        vector<int> v(n + 1, 0);
        for (int j = 1; j <= n; j++) {
            cin >> w[j] >> v[j];
        }

        for (int j = W; j >= 0; j--) {
            for (int k = 1; k <= n; k++) {
                if (j >= w[k]) {
                    dp[j] = max(dp[j], dp[j - w[k]] + v[k]);
                }
            }
        }
    }

    cout << dp[W] << endl;
    return 0;
}
