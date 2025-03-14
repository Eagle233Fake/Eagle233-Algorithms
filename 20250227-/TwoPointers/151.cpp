class Solution {
    public:
        string removeExtraSpaces(string& s) {
            int slow = 0, fast = 0;
            while (fast < s.size() && isspace(s[fast])) {
                fast++;
            }
            for (; fast < s.size(); fast++) {
                if (!isspace(s[fast])) {
                    if (slow != 0) {
                        s[slow++] = ' ';
                    }
                    while (fast < s.size() && !isspace(s[fast])) {
                        s[slow++] = s[fast++];
                    }
                }
            }
            s.resize(slow);
            return s;
        }
    
        string reverseWords(string s) {
            s = removeExtraSpaces(s);
            reverse(s.begin(), s.end());
            int slow = 0, fast = 0;
            for (; fast <= s.size(); fast++) {
                if (s[fast] == ' ' || fast == s.size()) {
                    reverse(s.begin() + slow, s.begin() + fast);
                    slow = fast + 1;
                }
            }
            return s;
        }
    };