class Solution {
    public:
        int largestSumAfterKNegations(vector<int>& nums, int k) {
            sort(nums.begin(), nums.end());
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] < 0) {
                    nums[i] = -nums[i];
                    k--;
                } else if (nums[i] == 0) {
                    k = 0;
                    break;
                } else {
                    break;
                }
                if (k == 0) {
                    break;
                }
            }
    
            sort(nums.begin(), nums.end());
    
            for (int i = 0; i < k; i++) {
                if (k % 2 == 1) {
                    nums[i] = -nums[i];
                    break;
                } else {
                    break;
                }
            }
    
            int sum = 0;
            for (int i = 0; i < nums.size(); i++) {
                sum += nums[i];
            }
    
            return sum;
        }
    };