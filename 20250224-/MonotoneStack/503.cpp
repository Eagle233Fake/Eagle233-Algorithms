class Solution {
    public:
        vector<int> nextGreaterElements(vector<int>& nums) {
            vector<int> result(nums.size(), -1);
            int length = nums.size();
            for (int i = 0; i < length; i++) {
                nums.push_back(nums[i]);
            }
            stack<int> st;
            st.push(0);
    
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] <= nums[st.top()]) {
                    st.push(i);
                } else {
                    while (!st.empty() && nums[i] > nums[st.top()]) {
                        result[st.top() % (nums.size() / 2)] = nums[i];
                        st.pop();
                    }
                    st.push(i);
                }
            }
    
            return result;
        }
    };