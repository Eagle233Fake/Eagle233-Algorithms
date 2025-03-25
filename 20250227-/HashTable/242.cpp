class Solution {
    public:
        bool isAnagram(string s, string t) {
            vector<int> v(26, 0);
            for (char c : s) {
                v[c - 'a'] += 1;
            }
            for (char c : t) {
                v[c - 'a'] -= 1;
            }
            for (int i : v) {
                if (i != 0) {
                    return false;
                }
            }
            return true;
        }
    };