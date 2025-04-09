class Solution {
    public:
        int findMaxForm(vector<string>& strs, int m, int n) {
            vector<int> One(strs.size(), 0);
            vector<int> Zero(strs.size(), 0);
    
            for (int i = 0; i < strs.size(); i++) {
                for (int j = 0; j < strs[i].size(); j++) {
                    if (strs[i][j] == '1') {
                        One[i]++;
                    } else {
                        Zero[i]++;
                    }
                }
            }
    
            vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
            for (int k = 0; k < strs.size(); k++) {
                for (int i = m; i >= Zero[k]; i--) {
                    for (int j = n; j >= One[k]; j--) {
                        dp[i][j] = max(dp[i][j], dp[i - Zero[k]][j - One[k]] + 1);
                    }
                }
            }
    
            return dp[m][n];
        }
    };