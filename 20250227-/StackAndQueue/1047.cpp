class Solution {
    public:
        string removeDuplicates(string s) {
            stack<char> st;
            for (char c : s) {
                if (st.empty()) {
                    st.push(c);
                    continue;
                } else {
                    if (st.top() == c) {
                        st.pop();
                    } else {
                        st.push(c);
                    }
                }
            }
    
            string s2;
            while (!st.empty()) {
                s2 += st.top();
                st.pop();
            }
    
            reverse(s2.begin(), s2.end());
            return s2;
        }
    };