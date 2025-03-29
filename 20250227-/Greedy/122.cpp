class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            vector<int> profit(prices.size(), 0);
            for (int i = 1; i < prices.size(); i++) {
                profit[i] = prices[i] - prices[i - 1];
            }
    
            int mmax = 0;
            for (int i = 1; i < prices.size(); i++) {
                if (profit[i] > 0) {
                    mmax += profit[i];
                }
            }
    
            return mmax;
        }
    }; 