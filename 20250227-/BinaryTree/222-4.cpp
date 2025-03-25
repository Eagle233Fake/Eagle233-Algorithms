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
        int countNodes(TreeNode* root) {
            if (root == nullptr) {
                return 0;
            }
            TreeNode *left = root->left;
            TreeNode *right = root->right;
            int leftDepth = 0;
            int rightDepth = 0;
    
            while (left != nullptr) {
                left = left->left;
                leftDepth++;
            }
            while (right != nullptr) {
                right = right->right;
                rightDepth++;
            }
            if (leftDepth == rightDepth) {
                return (1 << (leftDepth + 1)) - 1;
            }
    
            int leftNodes = countNodes(root->left);
            int rightNodes = countNodes(root->right);
            return leftNodes + rightNodes + 1;
        }
    };