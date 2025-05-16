#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, VV;
    cin >> N >> VV;

    vector<int> dp(VV + 1, 0);
    for (int i = 0; i < N; i++) {
        int s;
        cin >> s;
        vector<int> W(s, 0);
        vector<int> V(s, 0);
        for (int k = 0; k < s; k++) {
            cin >> W[k] >> V[k];
        }
        for (int j = VV; j >= 0; j--) {
            for (int k = 0; k < s; k++) {
                if (j >= W[k]) {
                    dp[j] = max(dp[j], dp[j - W[k]] + V[k]);
                }
            }
        }
    }

    cout << dp[VV] << endl;
    return 0;
}
