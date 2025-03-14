class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            int minLen = INT_MAX;
            int i = 0, j = 0;
            int sum = 0;
            for(; j < nums.size(); j++) {
                sum += nums[j];
                while (sum >= target) {
                    minLen = min(minLen, j - i + 1);
                    sum -= nums[i];
                    i++;
                }
            }
            if (minLen == INT_MAX) {
                return 0;
            }
            return minLen;
        }
    };