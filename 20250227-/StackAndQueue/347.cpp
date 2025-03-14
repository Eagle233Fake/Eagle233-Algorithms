class Solution {
    public:
        class cmp {
        public:
            bool operator()(const pair<int, int>& left, const pair<int, int>& right) {
                return left.second > right.second;
            }
        };
    
        vector<int> topKFrequent(vector<int>& nums, int k) {
            priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
            unordered_map<int, int> m;
            for (int i = 0; i < nums.size(); i++) {
                m[nums[i]]++;
            }
    
            for (auto& it : m) {
                pq.push(it);
                if (pq.size() > k) {
                    pq.pop();
                }
            }
    
            vector<int> v;
            for (int i = 0; i < k; i++) {
                v.push_back(pq.top().first);
                pq.pop();
            }
            return v;
        }
    };