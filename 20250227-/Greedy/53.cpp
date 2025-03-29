class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int count = 0;
            vector<int> result;
            for (int i = 0; i < nums.size(); i++) {
                count += nums[i];
                result.push_back(count);
                if (count < 0) {
                    count = 0;
                }
            }
    
            count = INT_MIN;
            for (int i = 0; i < nums.size(); i++) {
                count = max(count, result[i]);
            }
    
            return count;
        }
    };