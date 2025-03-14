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
                    j++;
                }
                next[i] = j;
            }
            return next;
        }
    
        bool repeatedSubstringPattern(string s) {
            vector<int> next = getNext(s);
            string ss = s + s;
            ss.erase(ss.begin());
            ss.pop_back();
            int j = 0;
            for (int i = 0; i < ss.size(); i++) {
                while (j > 0 && ss[i] != s[j]) {
                    j = next[j - 1];
                }
                if (ss[i] == s[j]) {
                    j++;
                }
                if (j == s.size()) {
                    return true;
                }
            }
            return false;
        }
    };