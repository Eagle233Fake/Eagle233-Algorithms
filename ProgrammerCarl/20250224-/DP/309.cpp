class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            vector<vector<int>> dp(prices.size(), vector<int>(4, 0));
            dp[0][0] = -prices[0];
            
            
            for (int i = 1; i < prices.size(); i++) {
                dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][2]  - prices[i], dp[i - 1][3] - prices[i])); // 持有
                dp[i][1] = dp[i - 1][0] + prices[i]; // 第一天买入
                dp[i][2] = dp[i - 1][1]; // 冷冻
                dp[i][3] = max(dp[i - 1][3], dp[i - 1][2]); // 冷冻后持有
            }
    
            int i = prices.size() - 1;
            return max(max(dp[i][1], dp[i][2]), dp[i][3]);
        }
    };