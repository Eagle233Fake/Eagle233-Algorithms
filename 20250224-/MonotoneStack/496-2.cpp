class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            vector<int> result(nums1.size(), -1);
            stack<int> st;
            unordered_map<int, int> umap;
            for (int i = 0; i < nums1.size(); i++) {
                umap[nums1[i]] = i;
            }
    
            st.push(nums2[0]);
            for (int i = 1; i < nums2.size(); i++) {
                if (nums2[i] <= st.top()) {
                    st.push(nums2[i]);
                } else {
                    while (!st.empty() && nums2[i] > st.top()) {
                        if (umap.count(st.top()) > 0) {
                            result[umap[st.top()]] = nums2[i];
                        }
                        st.pop();
                    }
                    st.push(nums2[i]);
                }
            }
    
            return result;
        }
    };