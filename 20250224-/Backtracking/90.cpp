class Solution {
    public:
        vector<vector<int>> v;
        vector<int> cur;
    
        void backtracking(vector<int> &nums, int index, vector<bool> &used) {
            v.push_back(cur);
            if (index >= nums.size()) {
                return;
            }
    
            for (int i = index; i < nums.size(); i++) {
                if (i > 0 && nums[i - 1] == nums[i] && !used[i - 1]) {
                    continue;
                }
                cur.push_back(nums[i]);
                used[i] = true;
                backtracking(nums, i + 1, used);
                used[i] = false;
                cur.pop_back();
            }
        }
    
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            vector<bool> used(nums.size(), false);
            backtracking(nums, 0, used);
            return v;
        }
    };