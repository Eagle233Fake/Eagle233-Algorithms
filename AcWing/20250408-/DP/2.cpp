#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, V;
    cin >> N >> V;
    vector<int> v(N + 1, 0);
    vector<int> w(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        cin >> w[i] >> v[i];
    }

    vector<int> dp(V + 1, 0);

    for (int i = 1; i <= N; i++) {
        for (int j = V; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }

    cout << dp[V] << endl;
    return 0;
}
