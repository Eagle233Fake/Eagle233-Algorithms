#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    while (m--) {
        string s;
        cin >> s;
        int mmax;
        cin >> mmax;
        int count = 0;
        for (string t : v) {
            vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
            
            for (int i = 0; i <= s.size(); i++) {
                dp[i][0] = i;
            }

            for (int j = 0; j <= t.size(); j++) {
                dp[0][j] = j;
            }

            for (int i = 1; i <= s.size(); i++) {
                for (int j = 1; j <= t.size(); j++) {
                    if (s[i - 1] == t[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1];
                    } else{
                        dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                    }
                }
            }
            if (dp[s.size()][t.size()] <= mmax) {
                count++;
            }
        }

        cout << count << endl;
    }
    return 0;
}
