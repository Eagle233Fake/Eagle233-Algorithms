class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            int result = INT_MAX;
            int sum = 0;
            int j = 0;
            int length;
            for (int i = 0; i < nums.size(); i++) {
                sum += nums[i];
                while (sum >= target) {
                    sum -= nums[j];
                    length = i - j + 1;
                    result = min(result, length);
                    j++;
                }
            }
    
            if (result == INT_MAX) {
                return 0;
            }
            return result;
        }
    };