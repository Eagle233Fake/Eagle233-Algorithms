class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            vector<int> dp(nums.size(), 1);
            int result = dp[0];
    
            for (int i = 1; i < nums.size(); i++) {
                for (int j = 0; j < i; j++) {
                    if (nums[j] < nums[i]) {
                        dp[i] = max(dp[j] + 1, dp[i]);
                    }
                }
                result = max(result, dp[i]);
            }
    
            return result;
        }
    };