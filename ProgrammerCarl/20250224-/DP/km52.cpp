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

    for (int i = 0; i < n; i++) {
        for (int j = w[i]; j <= v; j++) {
            dp[j] = max(dp[j], dp[j - w[i]] + val[i]);
        }
    }

    cout << dp[v] << endl;
}