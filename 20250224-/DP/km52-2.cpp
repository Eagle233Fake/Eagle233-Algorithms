#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n, v;
    cin >> n >> v;
    vector<int> w(n);
    vector<int> val(n);

    for (int i = 0; i < n; i++) {
        cin >> w[i] >> val[i];
    }

    vector<int> dp(v + 1, 0);

    for (int j = 0; j <= v; j++) {
        for (int i = 0; i < n; i++) {
            if (j >= w[i]) {
                dp[j] = max(dp[j], dp[j - w[i]] + val[i]);
            }
        }
    }

    cout << dp[v] << endl;
}