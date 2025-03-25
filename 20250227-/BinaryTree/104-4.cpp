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
        int result;
        void getDepth(TreeNode *node, int depth) {
            result = max(result, depth);
            if (node->left == nullptr && node->right == nullptr) {
                depth = 1;
            }
            if (node->left != nullptr) {
                getDepth(node->left, depth + 1);
            }
            if (node->right != nullptr) {
                getDepth(node->right, depth + 1);
            }
        }
        int maxDepth(TreeNode* root) {
            result = 0;
            if (root == nullptr) {
                return result;
            }
            getDepth(root, 1);
            return result;
        }
    };