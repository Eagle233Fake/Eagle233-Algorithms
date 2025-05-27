#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T, M;
    cin >> T >> M;
    vector<int> v(M, 0);
    vector<int> w(M, 0);

    for (int i = 0; i < M; i++) {
        cin >> w[i] >> v[i];
    }

    vector<int> dp(T + 1, 0);

    for (int i = 0; i < M; i++) {
        for (int j = T; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }

    cout << dp[T] << endl;
    return 0;
}
