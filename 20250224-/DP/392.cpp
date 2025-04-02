class Solution {
    public:
        bool isSubsequence(string s, string t) {
            vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
    
            for (int i = 1; i <= s.size(); i++) {
                for (int j = 1; j <= t.size(); j++) {
                    if (s[i - 1] == t[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    } else {
                        dp[i][j] = dp[i][j - 1];
                    }
                }
            }
    
            int mmax = INT_MIN;
            for (int j = 0; j <= t.size(); j++) {
                mmax = max(mmax, dp[s.size()][j]);
            }
            if (mmax == s.size()) {
                return true;
            }
            return false;
        }
    };