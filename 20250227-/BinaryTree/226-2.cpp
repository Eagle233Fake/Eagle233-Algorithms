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
        TreeNode* invertTree(TreeNode* root) {
            if (root == nullptr) {
                return root;
            }
            stack<TreeNode *> s;
            s.push(root);
            while (!s.empty()) {
                TreeNode *node = s.top();
                s.pop();
                swap(node->left, node->right);
                if (node->right != nullptr) {
                    s.push(node->right);
                }
                if (node->left != nullptr) {
                    s.push(node->left);
                }
            }
            return root;
        }
    };