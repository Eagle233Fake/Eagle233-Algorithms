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

    vector<vector<int>> dp(M, vector<int>(N + 1, 0));
    
    for (int i = 0; i < M; i++) {
        dp[i][0] = 0;
    }

    for (int j = 0; j <= N; j++) {
        if (w[0] <= j) {
            dp[0][j] = v[0];
        }
    }

    for (int i = 1; i < M; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= w[i]) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }

    cout << dp[M - 1][N] << endl;
}