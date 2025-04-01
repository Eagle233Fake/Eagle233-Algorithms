class Solution {
    public:
        vector<int> partitionLabels(string s) {
            unordered_map<char, int> m;
            for (int i = 0; i < s.size(); i++) {
                m[s[i]] = i;
            }
            int left = 0, right = 0;
            vector<int> v;
    
            while (left < s.size()) {
                int i = left;
                right = m[s[left]];
                while (left <= right) {
                    right = max(right, m[s[left]]);
                    left++;
                }
    
                v.push_back(left - i);
            }
    
            return v;
        }
    };