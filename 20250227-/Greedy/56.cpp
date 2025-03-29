class Solution {
    public:
        static bool cmp(vector<int> &a, vector<int> &b) {
            return a[0] < b[0];
        }
    
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            sort(intervals.begin(), intervals.end(), cmp);
    
            vector<vector<int>> v;
            for (int i = 1; i < intervals.size(); i++) {
                if (intervals[i][0] <= intervals[i - 1][1]) {
                    intervals[i][0] = min(intervals[i - 1][0], intervals[i][0]);
                    intervals[i][1] = max(intervals[i - 1][1], intervals[i][1]);
                } else {
                    v.push_back(intervals[i - 1]);
                }
            }
            v.push_back(intervals[intervals.size() - 1]);
            return v;
        }
    };