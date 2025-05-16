#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, VV;
    cin >> N >> VV;
    vector<int> W;
    vector<int> V;

    for (int i = 0; i <= N; i++) {
        int w, v, s;
        cin >> w >> v >> s;
        int t = 1;
        while (s - t > 0) {
            s -= t;
            W.push_back(w * t);
            V.push_back(v * t);
            t <<= 1;
        }

        if (s) {
            W.push_back(w * s);
            V.push_back(v * s);
        }
    }

    vector<int> dp(VV + 1, 0);

    for (int i = 0; i < W.size(); i++) {
        for (int j = VV; j >= W[i]; j--) {
            dp[j] = max(dp[j], dp[j - W[i]] + V[i]);
        }
    }

    cout << dp[VV] << endl;
    return 0;
}
