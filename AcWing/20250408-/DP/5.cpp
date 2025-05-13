#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, V;
    cin >> N >> V;

    vector<int> v;
    vector<int> w;
    vector<int> dp(V + 1, 0);
    for (int i = 1; i <= N; i++) {
        int w1, v1, s;
        cin >> w1 >> v1 >> s;
        for (int k = 1; k <= s; k <<= 1) {
            s -= k;
            v.push_back(v1 * k);
            w.push_back(w1 * k);
        }

        if (s) {
            v.push_back(s * v1);
            w.push_back(s * w1);
        }
    }

    for (int i = 0; i < v.size(); i++) {
        for (int j = V; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }

    cout << dp[V] << endl;
    return 0;
}
