class Solution {
    public:
        vector<vector<int>> v;
        vector<int> cur;
    
        void backtracking(vector<int> &nums, vector<bool> &used) {
            if (cur.size() == nums.size()) {
                v.push_back(cur);
                return;
            }
    
            for (int i = 0; i < nums.size(); i++) {
                if (!used[i]) {
                    cur.push_back(nums[i]);
                    used[i] = true;
                    backtracking(nums, used);
                    used[i] = false;
                    cur.pop_back();
                }
            }
        }
    
        vector<vector<int>> permute(vector<int>& nums) {
            vector<bool> used(nums.size(), false);
            backtracking(nums, used);
            return v;
        }
    };