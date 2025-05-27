#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, WW;
    cin >> N >> WW;
    vector<int> v;
    vector<int> w;
    while (N--) {
        int s, W, V;
        cin >> W >> V >> s;
        
        int t = 1;
        while (s - t > 0) {
            v.push_back(V * t);
            w.push_back(W * t);
            s -= t;
            t *= 2;
        }

        if (s) {
            v.push_back(V * s);
            w.push_back(W * s);
        }
    }

    vector<int> dp(WW + 1, 0);

    for (int i = 0; i < v.size(); i++) {
        for (int j = WW; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }

    cout << dp[WW] << endl;
    return 0;
}
