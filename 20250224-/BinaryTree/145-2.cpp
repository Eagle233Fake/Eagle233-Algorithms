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
            stack<TreeNode *> st;
            vector<int> v;
            st.push(root);
            while (!st.empty()) {
                TreeNode *node = st.top();
                st.pop();
                if (node != nullptr) {
                    v.push_back(node->val);
                } else {
                    continue;
                }
                st.push(node->left);
                st.push(node->right);
            }
            reverse(v.begin(), v.end());
            return v;
        }
    };