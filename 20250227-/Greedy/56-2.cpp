class Solution {
    public:
        static bool cmp(vector<int> &a, vector<int> &b) {
            return a[0] < b[0];
        }
    
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            sort(intervals.begin(), intervals.end(), cmp);
    
            vector<vector<int>> v;
            v.push_back(intervals[0]);
    
            for (int i = 1; i < intervals.size(); i++) {
                if (v.back()[1] >= intervals[i][0]) {
                    v.back()[1] = max(intervals[i][1], v.back()[1]);
                } else {
                    v.push_back(intervals[i]);
                }
            }
            return v;
        }
    };