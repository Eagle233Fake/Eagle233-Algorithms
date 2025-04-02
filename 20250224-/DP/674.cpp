class Solution {
    public:
        int findLengthOfLCIS(vector<int>& nums) {
            vector<int> dp(nums.size(), 1);
    
            int result = dp[0];
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i - 1] < nums[i]) {
                    dp[i] = dp[i - 1] + 1;
                }
                result = max(result, dp[i]);
    
            }
    
            return result;
        }
    };