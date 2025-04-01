class Solution {
    public:
        vector<int> cur;
        vector<vector<int>> v;
    
        void backtracking(vector<int> &candidates, int target, int index, int sum) {
            if (sum == target) {
                v.push_back(cur);
            } else if (sum > target) {
                return;
            }
    
            for (int i = index; i < candidates.size() && sum + candidates[i] <= target; i++) {
                cur.push_back(candidates[i]);
                backtracking(candidates, target, i, sum + candidates[i]);
                cur.pop_back();
            }
            return;
        }
    
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            sort(candidates.begin(), candidates.end());
            backtracking(candidates, target, 0, 0);
            return v;
        }
    };