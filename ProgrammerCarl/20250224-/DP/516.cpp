class Solution {
    public:
        int longestPalindromeSubseq(string s) {
            string t = s;
            reverse(t.begin(), t.end());
    
            vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
    
            for (int i = 1; i <= s.size(); i++) {
                for (int j = 1; j <= t.size(); j++) {
                    if (s[i - 1] == t[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    } else {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
    
            return dp[s.size()][t.size()];
        }
    };