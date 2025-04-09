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
        vector<int> inorderTraversal(TreeNode* root) {
            stack<TreeNode *> st;
            vector<int> v;
            TreeNode* node = root;
            while (node != nullptr || !st.empty()) {
                if (node != nullptr) {
                    st.push(node);
                    node = node->left;
                } else {
                    node = st.top();
                    st.pop();
                    v.push_back(node->val);
                    node = node->right;
                }
            }
            return v;
        }
    };