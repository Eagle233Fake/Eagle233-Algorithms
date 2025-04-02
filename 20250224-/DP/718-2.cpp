class Solution {
    public:
        int findLength(vector<int>& nums1, vector<int>& nums2) {
            vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), 0));
    
            int result = 0;
            for (int i = 0; i < nums1.size(); i++) {
                for (int j = 0; j < nums2.size(); j++) {
                    if (nums1[i] == nums2[j]) {
                        if (i == 0 || j == 0) {
                            dp[i][j] = 1;
                            result = max(result, dp[i][j]);
                            continue;
                        }
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    }
                    result = max(result, dp[i][j]);
                }
            }
    
            return result;
        }
    };