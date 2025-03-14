class Solution {
    public:
        int findTargetSumWays(vector<int>& nums, int target) {
            int length = nums.size();
            int sum = 0;
            for (int i = 0; i < length; i++) {
                sum += nums[i];
            }
            sum += target;
            if (sum % 2 == 1 || abs(target) > sum - target) {
                return 0;
            }
    
            vector<int> dp(sum / 2 + 1, 0);
            dp[0] = 1;
    
            for (int i = 0; i < length; i++) {
                for (int j = sum / 2; j >= nums[i]; j--) {
                    dp[j] = dp[j] + dp[j - nums[i]];
                }
            }
    
            return dp[sum / 2];
        }
    };