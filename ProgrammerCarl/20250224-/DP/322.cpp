class Solution {
    public:
        int coinChange(vector<int>& coins, int amount) {
            vector<int> dp(amount + 1, INT_MAX);
            dp[0] = 0;
    
            // for (int j = 0; j <= amount; j++) {
            //     if (j % coins[0] == 0) {
            //         dp[j] = j / coins[0];
            //     }
            // }
    
            for (int i = 0; i < coins.size(); i++) {
                for (int j = coins[i]; j <= amount; j++) {
                    if (dp[j - coins[i]] != INT_MAX) {
                        dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                    }
                }
            }
            
            if (dp[amount] == INT_MAX) {
                return -1;
            }
    
            return dp[amount];
        }
    };