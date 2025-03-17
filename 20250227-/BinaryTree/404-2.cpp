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
        int sumOfLeftLeaves(TreeNode* root) {
            stack<TreeNode *> st;
            if (root != nullptr) {
                st.push(root);
            }
            int sum = 0;
            while (!st.empty()) {
                TreeNode *node = st.top();
                st.pop();
                if (node->left != nullptr) {
                    st.push(node->left);
                    if (node->left->left == nullptr && 
                        node->left->right == nullptr) {
                        sum += node->left->val;
                    }
                }
                if (node->right != nullptr) {
                    st.push(node->right);
                }
            }
    
            return sum;
        }
    };