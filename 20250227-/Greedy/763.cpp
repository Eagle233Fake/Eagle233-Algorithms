class Solution {
    public:
        vector<int> partitionLabels(string s) {
            unordered_map<char, int> m;
            for (int i = 0; i < s.size(); i++) {
                m[s[i]] = i;
            }
    
            int left = 0, right = 0;
            vector<int> v;
            for (int i = 0; i < s.size(); i++) {
                right = max(right, m[s[i]]);
                if (i == right) {
                    v.push_back(right - left + 1);
                    left = right + 1;
                }
            }
    
            return v;
        }
    };