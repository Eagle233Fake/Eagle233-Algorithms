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
        bool traversal(TreeNode* root, int targetSum) {
            if (root->left == nullptr && root->right == nullptr && targetSum == 0) {
                return true;
            }
            if (root->left != nullptr) {
                if (traversal(root->left, targetSum - root->left->val)) {
                    return true;
                }
            }
            if (root->right != nullptr) {
                if (traversal(root->right, targetSum - root->right->val)) {
                    return true;
                }            
            }
            return false;
        }
    
        bool hasPathSum(TreeNode* root, int targetSum) {
            if (root == nullptr) {
                return false;
            }
            return traversal(root, targetSum - root->val);
        }
    };