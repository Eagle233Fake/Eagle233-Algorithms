class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int length = nums.size();
            vector<int> dp(1000000, nums[0]);
            int ans = nums[0];
            for (int i = 1; i < length; i++) {
                dp[i] = max(nums[i], dp[i - 1] + nums[i]);
                ans = max(ans, dp[i]);
            }
            return ans;
        }
    };