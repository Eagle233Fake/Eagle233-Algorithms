class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> n(prices.size(), 0);
        for (int i = 1; i < prices.size(); i++) {
            n[i] = prices[i] - prices[i - 1];
        }

        int sum = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (n[i] > 0) {
                sum += n[i];
            }
        }

        return sum;
    }
};