class Solution {
    public:
        vector<vector<int>> v;
        vector<int> cur;
    
        void backtracking(vector<int> &nums, int index) {
            if (cur.size() >= 2) {
                v.push_back(cur);
            }
    
            unordered_set<int> used;
            for (int i = index; i < nums.size(); i++) {
                if ((!cur.empty() && nums[i] < cur.back()) || used.find(nums[i]) != used.end()) {
                    continue;
                }
    
                cur.push_back(nums[i]);
                used.insert(nums[i]);
                backtracking(nums, i + 1);
                cur.pop_back();
            }
        }
    
        vector<vector<int>> findSubsequences(vector<int>& nums) {
            backtracking(nums, 0);
            return v;
        }
    };