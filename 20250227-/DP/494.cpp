class Solution {
    public:
        int findTargetSumWays(vector<int>& nums, int target) {
            int sum = 0;
            for (int i = 0; i < nums.size(); i++) {
                sum += nums[i];
            }
            sum += target;
            if (sum % 2 == 1 || abs(target) > sum - target) {
                return 0;
            }
    
            vector<vector<int>> dp(nums.size() + 1, vector<int>(sum / 2 + 1, 0)); // 表示使用0-i个物品时，容量为j的背包有多少装的方法
    
            for (int i = 0; i < nums.size() + 1; i++) {
                dp[i][0] = 1; // 背包大小为0时，考虑物品的大小决定装不装
            }
    
            for (int i = 1; i <= nums.size(); i++) {
                for (int j = 0; j <= sum / 2; j++) {
                    if (j < nums[i - 1]) {
                        dp[i][j] = dp[i - 1][j];
                    } else {
                        dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                    }
                }
            }
    
    
            return dp[nums.size()][sum / 2];
        }
    };