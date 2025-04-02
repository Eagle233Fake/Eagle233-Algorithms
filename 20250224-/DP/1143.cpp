class Solution {
    public:
        int longestCommonSubsequence(string text1, string text2) {
            vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), 0)); // 不是以i j结尾 是长度从0到i j
    
            for (int i = 0; i < text1.size(); i++) {
                for (int j = 0; j < text2.size(); j++) {
                    if (text1[i] == text2[j]) {
                        if (i == 0 || j == 0) {
                            dp[i][j] = 1;
                        } else {
                            dp[i][j] = dp[i - 1][j - 1] + 1;
                        }
                    } else {
                        if (i == 0 && j != 0) {
                            dp[i][j] = dp[i][j - 1];
                        } else if (j == 0 && i != 0) {
                            dp[i][j] = dp[i - 1][j];
                        } else if (j == 0 && i == 0) {
                            dp[i][j] = 0;
                        } else {
                            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                        }
                    }
                }
            }
    
            return dp[text1.size() - 1][text2.size() - 1];
        }
    };