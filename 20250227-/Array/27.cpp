class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            int size = nums.size();
            for (int i = 0; i < size; i++) {
                if (val == nums[i]) {
                    for (int j = i + 1; j < size; j++) {
                        nums[j - 1] = nums[j];
                    }
                    size--;
                    i--;
                }
            }
            return size;
        }
    };