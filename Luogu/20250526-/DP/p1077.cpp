#include <bits/stdc++.h>

using namespace std;

const int mod = 1e6 + 7;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    vector<int> s(n);
    // for (int i = 0; i < n; i++) {
    //     int S;
    //     cin >> S;
    //     int t = 1;  
    //     while (S - t > 0) {
    //         s.push_back(t);
    //         S -= t;
    //         t *= 2;
    //     }
    //     if (S) {
    //         s.push_back(S);
    //     }
    // }
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    vector<int> dp(m + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = ) {
            for (int k = 0; k <= s[i]; k++) {
                if (j >= k) {
                    dp[j] = max(dp[j], dp[j - k]);
                }
            }
        }
    } 

    cout << dp[m] << endl;

    return 0;
}
