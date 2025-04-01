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
        int minDepth(TreeNode* root) {
            if (root == nullptr) {
                return 0;
            }
            int left = minDepth(root->left);
            int right = minDepth(root->right);
            if (root->left != nullptr && root->right == nullptr) {
                return 1 + left;
            }
            if (root->right != nullptr && root->left == nullptr) {
                return 1 + right;
            }
            return 1 + min(left, right);
        }
    };