class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int mmin = INT_MAX;
            int result = INT_MIN;
    
            for (int i = 0; i < prices.size(); i++) {
                mmin = min(mmin, prices[i]);
                result = max(result, prices[i] - mmin);
            }
    
            return result;
        }
    };