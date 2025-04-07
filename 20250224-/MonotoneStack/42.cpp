class Solution {
    public:
        int trap(vector<int>& height) {
            int result = 0;
            stack<int> st;
            st.push(0);
    
            for (int i = 1; i < height.size(); i++) {
                if (height[i] <= height[st.top()]) {
                    st.push(i);
                } else {
                    while (!st.empty() && height[i] > height[st.top()]) {
                        int mid = st.top();
                        st.pop();
                        if (!st.empty()) {
                            result += (min(height[i], height[st.top()]) - height[mid]) * (i - st.top() - 1);
                        }       
                    }
                    st.push(i);
                }
            }
    
            return result;
        }
    };