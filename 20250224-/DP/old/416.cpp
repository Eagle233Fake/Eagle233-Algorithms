class Solution {
    public:
        bool canPartition(vector<int>& nums) {
            int length = nums.size();
    
            int sum = 0;
            for (int i = 0; i < length; i++) {
                sum += nums[i];
            }
    
            if (sum % 2 == 1) {
                return false;
            }
    
            vector<int> dp(sum / 2 + 1, 0);
            for (int i = 0; i < length; i++) {
                for (int j = sum / 2; j >= nums[i]; j--) {
                    dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
                }
    
                if (dp[sum / 2] == sum / 2) {
                    return true;
                }
            }
    
            return false;
        }
    };