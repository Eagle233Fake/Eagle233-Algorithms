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
            if (left == nullptr && right == nullptr) {
                return true;
            } else if (left == nullptr || right == nullptr) {
                return false;
            } else {
                return left->val == right->val && cmp(left->left, right->left) && cmp(left->right, right->right);
            }
    
        }
    
        bool isSubtree(TreeNode* root, TreeNode* subRoot) {
            if (root == nullptr && subRoot == nullptr) {
                return true;
            } else if (root == nullptr && subRoot != nullptr) {
                return false;
            }
            if (cmp(root, subRoot)) {
                return true;
            }
            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        }
    };