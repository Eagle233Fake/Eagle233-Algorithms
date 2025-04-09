class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            vector<int> dp(2500, 1);
            int mmax = 1;
            for (int i = 1; i < nums.size(); i++) {
                for (int j = 0; j < i; j++) {
                    if (nums[j] < nums[i]) {
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
    
                    mmax = max(mmax, dp[i]);
                }
            }
            return mmax;
        }
    };