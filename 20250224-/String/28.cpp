class Solution {
    public:
        vector<int> getNext(string& s) {
            int j = 0;
            vector<int> next(s.size());
            next[0] = 0;
            for (int i = 1; i < s.size(); i++) {
                while (s[i] != s[j] && j > 0) {
                    j = next[j - 1];
                }
                if (s[i] == s[j]) {
                    next[i] = j + 1;
                    j++;
                    continue;
                } else {
                    next[i] = 0;
                }
    
            }
            return next;
        }
    
        int strStr(string haystack, string needle) {
            vector<int> next = getNext(needle);
            int j = 0;
            for (int i = 0; i < haystack.size(); i++) {
                while (haystack[i] != needle[j] && j > 0) {
                    j = next[j - 1];
                }
                if (j == 0 && haystack[i] != needle[j]) {
                    continue;
                }
                if (haystack[i] == needle[j]) {
                    j++;
                }
                if (j == needle.size()) {
                    return i + 1 - needle.size();
                }
            }
            return -1;
        }
    };