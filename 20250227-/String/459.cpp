class Solution {
    public:
        vector<int> getNext(string s) {
            vector<int> next(s.size());
            next[0] = 0;
            int j = 0;
            for (int i = 1; i < s.size(); i++) {
                while (s[i] != s[j] && j > 0) {
                    j = next[j - 1];
                }
                if (s[i] == s[j]) {
                    next[i] = j + 1;
                    j++;
                } else {
                    next[i] = 0;
                }
            }
            return next;
        }
    
        bool repeatedSubstringPattern(string s) {
            vector<int> next = getNext(s);
            if (next[s.size() - 1] == 0) {
                return false;
            }
            if ((s.size() - next[s.size() - 1]) != 0 && s.size() % (s.size() - next[s.size() - 1]) == 0) {
                return true;
            }
            return false;
        }
    };