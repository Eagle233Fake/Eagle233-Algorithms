class Solution {
    public:
        static bool cmp(vector<int> &a, vector<int> &b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] > b[0];
        }
    
        vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
            sort(people.begin(), people.end(), cmp);
    
            list<vector<int>> queue;
            for (int i = 0; i < people.size(); i++) {
                list<vector<int>>::iterator it = queue.begin();
                int position = people[i][1];
                while (position--) {
                    it++;
                }
                queue.insert(it, people[i]);
            }
    
            return vector<vector<int>>(queue.begin(), queue.end());
        }
    };