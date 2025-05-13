#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, V;
    cin >> N >> V;
    vector<int> dp(V + 1, 0);

    for (int i = 0; i < N; i++) {
        int s;
        cin >> s;
        vector<int> w(s + 1, 0);
        vector<int> v(s + 1, 0);
        for (int j = 1; j <= s; j++) {
            cin >> w[j] >> v[j];
        }
        
        for (int j = V; j >= 0; j--) {
            for (int k = 1; k <= s; k++) {
                if (j >= w[k]) {
                    dp[j] = max(dp[j], dp[j - w[k]] + v[k]);
                }
            }
        }
    }

    cout << dp[V] << endl;
    return 0;
}
