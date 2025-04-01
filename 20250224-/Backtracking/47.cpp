class Solution {
    public:
        vector<vector<int>> v;
        vector<int> cur;
    
        void backtracking(vector<int> &nums, vector<int> &used) {
            if (cur.size() == nums.size()) {
                v.push_back(cur);
                return;
            }
            
            unordered_set<int> uset;
            for (int i = 0; i < nums.size(); i++) {
                if (used[i] || uset.find(nums[i]) != uset.end()) {
                    continue;
                } else {
                    cur.push_back(nums[i]);
                    uset.insert(nums[i]);
                    used[i] = true;
                    backtracking(nums, used);
                    used[i] = false;
                    cur.pop_back();
                }
            }
        }
    
        vector<vector<int>> permuteUnique(vector<int>& nums) {
            vector<int> used(nums.size(), false);
            backtracking(nums, used);
            return v;
        }
    };