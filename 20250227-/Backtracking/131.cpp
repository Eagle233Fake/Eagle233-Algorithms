class Solution {
    public:
        vector<vector<string>> v;
        vector<string> cur;
    
        bool isPalindrome(string &s, int i, int j) {
            for (; i <= j; i++, j--) {
                if (s[i] != s[j]) {
                    return false;
                }
            }
            return true;
        }
        
        void backtracking(string &s, int index) {
            if (index >= s.size()) {
                v.push_back(cur);
            }
    
            for (int i = index; i < s.size(); i++) {
                if (isPalindrome(s, index, i)) {
                    cur.push_back(s.substr(index, i - index + 1));
                    backtracking(s, i + 1);
                    cur.pop_back();
                } else {
                    continue;
                }
            }
        }
    
        vector<vector<string>> partition(string s) {
            backtracking(s, 0);
            return v;
        }
    };