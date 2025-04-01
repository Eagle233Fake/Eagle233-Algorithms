class Solution {
    public:
        vector<string> v;
        vector<string> cur;
    
        bool isLegal(string &s, int i, int j) {
            if (s[i] == '0' && i != j) {
                return false;
            }
            if (j - i + 1 > 3) {
                return false;
            }
            int num = 0;
            for (int index = i; index <= j; index++) {
                num *= 10;
                if (!isdigit(s[index])) {
                    return false;
                }
                num += s[index] - '0';
            }
            if (num >= 0 && num <= 255) {
                return true;
            }
            return false;
        }
    
        void backtracking(string &s, int index) {
            if (index >= s.size() && cur.size() == 4) {
                string ne;
                ne = cur[0] + "." + cur[1] + "." + cur[2] + "." + cur[3];
                v.push_back(ne);
                return;
            } else if (index >= s.size() && cur.size() < 4) {
                return;
            }
    
            for (int i = index; i < s.size(); i++) {
                if (isLegal(s, index, i)) {
                    cur.push_back(s.substr(index, i - index + 1));
                    backtracking(s, i + 1);
                    cur.pop_back();
                } else {
                    continue;
                }
            }
        }
    
        vector<string> restoreIpAddresses(string s) {
            backtracking(s, 0);
            return v;
        }
    };