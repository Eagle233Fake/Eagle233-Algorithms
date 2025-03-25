class Solution {
    public:
        vector<int> sortedSquares(vector<int>& nums) {
            int k = nums.size() - 1;
            vector<int> v(k + 1);
            for (int i = 0, j = k; i <= j;) {
                if (nums[i] * nums[i] < nums[j] * nums[j]) {
                    v[k--] = nums[j] * nums[j];
                    j--;
                } else {
                    v[k--] = nums[i] * nums[i];
                    i++;
                }
            }
    
            return v;
        }
    };