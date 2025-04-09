class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int result = 0;
            int mmax = INT_MIN;
    
            for (int i = 0; i < nums.size(); i++) {
                result += nums[i];
                mmax = max(result, mmax);
                if (result < 0) {
                    result = 0;
                }
            }
    
            return mmax;
        }
    };