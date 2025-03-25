class Solution {
    public:
        void removeExtraSpaces(string& s) {
            int slow = 0;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] != ' ') {
                    if (slow != 0) {
                        s[slow] = ' ';
                        slow++;
                    }
                    while (i < s.size() && s[i] != ' ') {
                        s[slow++] = s[i++];
                    }
                }
            }
            s.resize(slow);
        }
    
        string reverseWords(string s) {
            removeExtraSpaces(s);
            reverse(s.begin(), s.end()); // reverse左闭右开
            int count = 0;
            for (int i = 0; i <= s.size(); i++) {
                if (s[i] == ' ' || i == s.size()) {
                    reverse(s.begin() + i - count, s.begin() + i);
                    count = 0;
                }
                if (s[i] != ' ') {
                    count++;
                }
            }
            return s;
        }
    };