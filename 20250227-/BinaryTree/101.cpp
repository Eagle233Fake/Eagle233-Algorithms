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
        bool cmp(TreeNode *left, TreeNode *right) {
            if (left == nullptr && right != nullptr) {
                return false;
            } else if (right == nullptr && left != nullptr) {
                return false;
            } else if (left == nullptr && right == nullptr) {
                return true;
            } else if (left->val != right->val) {
                return false;
            }
            return cmp(left->left, right->right) && cmp(left->right, right->left);
        }
    
        bool isSymmetric(TreeNode* root) {
            return cmp(root->left, root->right);
        }
    };