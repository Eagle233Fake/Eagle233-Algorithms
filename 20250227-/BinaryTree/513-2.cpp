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
        int maxDepth = INT_MIN;
        void traversal(TreeNode *node, int depth) {
            if (node->left == nullptr && node->right == nullptr) {
                if (depth > maxDepth) {
                    maxDepth = depth;
                    result = node->val;
                    return;
                }
            }
    
            if (node->left != nullptr) {
                traversal(node->left, depth + 1);
            }
            if (node->right != nullptr) {
                traversal(node->right, depth + 1);
            }
        }
        int findBottomLeftValue(TreeNode* root) {
            traversal(root, 1);
            return result;
        }
    };