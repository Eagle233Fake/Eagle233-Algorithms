#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, W;
    cin >> N >> W;
    vector<int> dp(W + 1, 0);

    while (N--) {
        int s;
        cin >> s;
        vector<int> v(s);
        vector<int> w(s);
        for (int i = 0; i < s; i++) {
            cin >> w[i] >> v[i];
        }

        for (int j = W; j >= 0; j--) {
            for (int i = 0; i < s; i++) {
                if (j >= w[i]) {
                    dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
                }
            }
        }
    }

    cout << dp[W] << endl;
    return 0;
}
