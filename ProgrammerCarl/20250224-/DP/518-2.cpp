class Solution {
    public:
        int change(int amount, vector<int>& coins) {
            vector<vector<unsigned long long>> dp(coins.size(), vector<unsigned long long>(amount + 1, 0));
    
            for (int j = 0; j <= amount; j++) {
                if (j % coins[0] == 0) {
                    dp[0][j] = 1;
                }
            }
    
            for (int i = 0; i < coins.size(); i++) {
                dp[i][0] = 1;
            }
    
            for (int i = 1; i < coins.size(); i++) {
                for (int j = 0; j <= amount; j++) {
                    dp[i][j] = dp[i - 1][j];
                    if (j >= coins[i]) {
                        dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]];
                    }
                }
            }
    
            return dp[coins.size() - 1][amount];
        }
    };