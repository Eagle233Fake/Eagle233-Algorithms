/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
        vector<int> findMode(TreeNode* root) {
            stack<TreeNode *> st;
            vector<int> v;
            int maxCount = 0;
            int count = 0;
            TreeNode *pre = nullptr;
            TreeNode *cur = root;
            while (cur != nullptr || !st.empty()) {
                if (cur != nullptr) {
                    st.push(cur);
                    cur = cur->left;
                } else {
                    cur = st.top();
                    st.pop();
                    if (pre == nullptr) {
                        count = 1;
                    } else if (pre->val == cur->val) {
                        count++;
                    } else if (pre->val != cur->val) {
                        count = 1;
                    }
    
                    if (maxCount == count) {
                        v.push_back(cur->val);
                    }
                    if (count > maxCount) {
                        v.clear();
                        maxCount = count;
                        v.push_back(cur->val);
                    }
                    pre = cur;
                    cur = cur->right;
                } 
            }
    
            return v;
        }
    };