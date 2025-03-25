class Solution {
    public:
        vector<int> cur;
        vector<vector<int>> v;
    
        void backtracking(vector<int> &nums, int index) {
            v.push_back(cur);
            if (index >= nums.size()) {
                return;
            }
    
            for (int i = index; i < nums.size(); i++) {
                cur.push_back(nums[i]);
                backtracking(nums, i + 1);
                cur.pop_back();
            }
        }
    
        vector<vector<int>> subsets(vector<int>& nums) {
            backtracking(nums, 0);
            return v;
        }
    };