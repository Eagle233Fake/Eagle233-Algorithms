class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            int size = nums.size();
            int slowIndex = 0, fastIndex = 0;
            for (int fastIndex = 0; fastIndex < size; fastIndex++)
            {
                if (nums[fastIndex] != val) {
                    nums[slowIndex] = nums[fastIndex];
                    slowIndex++;
                }
            }
    
            return slowIndex;
        }
    };