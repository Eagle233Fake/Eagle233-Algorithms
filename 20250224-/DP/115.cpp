class Solution {
    public:
        int numDistinct(string s, string t) {
            vector<vector<unsigned long long>> dp(s.size() + 1, vector<unsigned long long>(t.size() + 1, 0)); // 0到i-1 以j-1为结尾
            for (int i = 0; i <= s.size(); i++) {
                dp[i][0] = 1;
            }
            for (int j = 0; j <= t.size(); j++) {
                dp[0][j] = 0;
            }
            dp[0][0] = 1;
            
            for (int i = 1; i <= s.size(); i++) {
                for (int j = 1; j <= t.size(); j++) {
                    if (s[i - 1] == t[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] % ((unsigned long long)pow(10, 9) + 7);
                    } else {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }
    
            return dp[s.size()][t.size()];
        }
    };