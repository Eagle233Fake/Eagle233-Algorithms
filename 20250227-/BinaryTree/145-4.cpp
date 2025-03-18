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
        vector<int> postorderTraversal(TreeNode* root) {
            vector<int> v;
            stack<TreeNode *> st;
            if (root != nullptr) {
                st.push(root);
            }
            while (!st.empty()) {
                TreeNode *node = st.top();
                st.pop();
                v.push_back(node->val);
                if (node->left != nullptr) {
                    st.push(node->left);
                }
                if (node->right != nullptr) {
                    st.push(node->right);
                }
            }
            reverse(v.begin(), v.end());
            return v;
        }
    };