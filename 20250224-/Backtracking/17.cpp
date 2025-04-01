class Solution {
    public:
        string map[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> v;
        string cur;
        void backtracking(string digits, int index) {
            if (cur.length() == digits.length()) {
                v.push_back(cur);
                return;
            }
    
            int digit = digits[index] - '0';
            string s = map[digit];
            for (char c : s) {
                cur.push_back(c);
                backtracking(digits, index + 1);
                cur.pop_back();
            }
            return;
        }
    
        vector<string> letterCombinations(string digits) {
            if (digits == "") {
                return v;
            }
            backtracking(digits, 0);
            return v;
        }
    };