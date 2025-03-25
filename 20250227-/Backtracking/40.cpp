class Solution {
    public:
        vector<vector<int>> v;
        vector<int> cur;
        
        void backtracking(vector<int> &candidates, int target, int sum, int index, vector<bool> &used) {
            if (sum == target) {
                v.push_back(cur);
                return;
            } else if (sum > target) {
                return;
            }
    
            for (int i = index; i < candidates.size() && sum + candidates[i] <= target; i++) {
                if (i > 0 && candidates[i - 1] == candidates[i] && !used[i - 1]) {
                    continue;
                }
                cur.push_back(candidates[i]);
                used[i] = true;
                backtracking(candidates, target, sum + candidates[i], i + 1, used);
                used[i] = false;
                cur.pop_back();
            }
            return;
        }
    
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            vector<bool> used(candidates.size(), false);
            sort(candidates.begin(), candidates.end());
            backtracking(candidates, target, 0, 0, used);
            return v;
        }
    };