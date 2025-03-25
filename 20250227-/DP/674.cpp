class Solution {
    public:
        int findLengthOfLCIS(vector<int>& nums) {
            vector<int> dp(100000, 1);
            int length = nums.size();
            int mmax = 1;
            for (int i = 1; i < length; i++) {
                if (nums[i - 1] < nums[i]) {
                    dp[i] = dp[i - 1] + 1;
                }
    
                mmax = max(dp[i], mmax);
            }
    
            return mmax;
        }
    };