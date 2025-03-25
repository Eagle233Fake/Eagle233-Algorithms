class Solution {
    public:
        bool repeatedSubstringPattern(string s) {
            string ss = s + s;
            ss.erase(ss.begin());
            ss.pop_back();
            if (ss.find(s) != string::npos) { // 注意 string::npos
                return true;
            }
            return false;
        }
    };