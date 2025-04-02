class Solution {
    public:
        int countSubstrings(string s) {
            int result = 0;
            for (int i = 0; i < s.size(); i++) {
                result += extend(s, i, i, s.size());
                result += extend(s, i, i + 1, s.size());
            }
            return result;
        }
    
        int extend(string &s, int i, int j, int size) {
            int result = 0;
            while (i >= 0 && j < size && s[i] == s[j]) {
                i--;
                j++;
                result++;
            }
            return result;
        }
    };