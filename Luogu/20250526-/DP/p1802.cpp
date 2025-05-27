#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, x;
    cin >> n >> x;

    vector<int> lose(n), win(n), use(n);
    for (int i = 0; i < n; i++) {
        cin >> lose[i] >> win[i] >> use[i];
    }

    vector<ull> dp(x + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = x; j >= 0; j--) {
            if (j >= use[i]) {
                dp[j] = max(dp[j] + lose[i], dp[j - use[i]] + win[i]);
            } else {
                dp[j] += lose[i];
            }
            
        }
    }

    cout << dp[x] * 5 << endl;
    return 0;
}
