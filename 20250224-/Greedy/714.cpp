class Solution {
    public:
        int maxProfit(vector<int>& prices, int fee) {
            int result = 0;
            int minPrice = INT_MAX; // 作为买入价格
            for (int i = 0; i < prices.size(); i++) {
                minPrice = min(minPrice, prices[i]);
    
                if (prices[i] > minPrice + fee) {
                    result += prices[i] - minPrice - fee;
                    minPrice = prices[i] - fee; // 防止多扣除fee
                }
            }
    
            return result;
        }
    };