class Solution {
    public:
        bool canPartition(vector<int>& nums) {
            int sum = 0;
            for (int j = 0; j < nums.size(); j++) {
                sum += nums[j];
            }
    
            if (sum % 2 == 1) {
                return false;
            }
    
            vector<int> dp(sum / 2 + 1, 0);
    
            for (int i = 0; i < nums.size(); i++) {
                for (int j = sum / 2; j >= nums[i]; j--) {
                    dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
                }
            }
    
            if (dp[sum / 2] == sum / 2) {
                return true;
            }
            return false;
        }
    };