class Solution {
    public:
        bool isValid(string s) {
            int l = s.size();
            if (l % 2 == 1) {
                return false;
            }
            stack<char> a;
            bool isFirst = true;
            for (char c : s) {
                if (c == '(') {
                    a.push(')');
                } else if (c == '[') {
                    a.push(']');
                } else if (c == '{') {
                    a.push('}');
                }
                if (a.empty() && !isFirst) {
                    return false;
                }
                isFirst = false;
                if (c == '}' || c == ']' || c == ')') {
                    if (!a.empty() && a.top() == c) {
                        a.pop();
                    } else {
                        return false;
                    }
                }
            }
    
            if (!a.empty()) {
                return false;
            }
            return true;
        }
    };