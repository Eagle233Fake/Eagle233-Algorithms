#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;

    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));

    for (int i = 1; i <= a.size(); i++) {
        for (int j = 1; j <= b.size(); j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            } 
        }
    }

    cout << dp[a.size()][b.size()] << endl;
    return 0;
}
