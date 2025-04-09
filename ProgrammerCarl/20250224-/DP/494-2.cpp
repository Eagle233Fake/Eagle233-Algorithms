class Solution {
    public:
        int findTargetSumWays(vector<int>& nums, int target) {
            int sum = 0;
            int zeroSum = 0;
    
            for (int i = 0; i < nums.size(); i++) {
                sum += nums[i];
            }
    
            if (abs(target) > sum) {
                return 0;
            }
            if ((sum + target) % 2 == 1) {
                return 0;
            }
    
            int size = target + (sum - target) / 2;
            vector<vector<int>> dp(nums.size(), vector<int>(size + 1, 0));
    
            dp[0][0] = 1;
            if (size >= nums[0]) {
                dp[0][nums[0]] = 1; // 限定
            }
    
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == 0) {
                    zeroSum++;
                }
                dp[i][0] = 1 << zeroSum; // 动态变化 zeroSum
            }
    
            for (int i = 1; i < nums.size(); i++) {
                for (int j = 1; j <= size; j++) {
                    dp[i][j] = dp[i - 1][j];
                    if (j >= nums[i]) {
                        dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i]];
                    }
                }
            }
    
            return dp[nums.size() - 1][size];
        }
    };