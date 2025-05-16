#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<string> s(n);

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    while (m--) {
        string b;
        cin >> b;
        int upper;
        cin >> upper;
        int count = 0;
        for (string a : s) {
            vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));
            for (int i = 0; i <= a.size(); i++) {
                dp[i][0] = i;
            }
            for (int j = 0; j <= b.size(); j++) {
                dp[0][j] = j;
            }

            for (int i = 1; i <= a.size(); i++) {
                for (int j = 1; j <= b.size(); j++) {
                    if (a[i - 1] == b[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1];
                    } else {
                        dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                    }
                }
            }

            if (dp[a.size()][b.size()] <= upper) {
                count++;
            }
        }

        cout << count << endl;
    }
    return 0;
}
