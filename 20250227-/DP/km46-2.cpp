#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int M, N;
    cin >> M >> N;

    vector<int> w(M);
    vector<int> v(M);

    for (int i = 0; i < M; i++) {
        cin >> w[i];
    }

    for (int i = 0; i < M; i++) {
        cin >> v[i];
    }

    vector<int> dp(N + 1, 0);

    for (int i = 0; i < M; i++) {
        for (int j = N; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }

    cout << dp[N] << endl;
}