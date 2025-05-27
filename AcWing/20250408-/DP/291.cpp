#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    while (cin >> N >> M, N || M) {
        int n = N, m = 1 << M;
        vector<vector<long long>> dp(n + 1, vector<long long>(m, 0));
        vector<bool> st(m, true);

        for (int i = 0; i < m; i++) {
            int count = 0;
            for (int j = 0; j < M; j++) {
                if (i >> j & 1) {
                    if (count & 1) {
                        st[i] = false;
                        break;
                    } else {
                        count = 0;
                    }
                } else {
                    count++;
                }
            }
            
            if (count & 1) {
                st[i] = false;
            }
        }

        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < m; k++) {
                    if ((j & k) == 0 && st[j | k]) {
                        dp[i][j] += dp[i - 1][k];
                    }
                }
            }
        }

        cout << dp[N][0] << endl;
    }
    
}
