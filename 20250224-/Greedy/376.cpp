class Solution {
    public:
        int wiggleMaxLength(vector<int>& nums) {
            int predif = 0;
            int curdif = 0;
    
            int count = 1;
            for (int i = 0; i < nums.size() - 1; i++) {
                curdif = nums[i + 1] - nums[i];
                if ((predif <= 0 && curdif > 0) || (predif >= 0 && curdif < 0)) {
                    count++;
                    predif = curdif;
                }
            }
    
            return count;
        }
    };