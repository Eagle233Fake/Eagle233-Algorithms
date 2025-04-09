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
    TreeNode *pre = nullptr;
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        bool left = isValidBST(root->left);
        if (pre == nullptr || pre->val < root->val) {
            pre = root;
        } else {
            return false;
        }
        bool right = isValidBST(root->right);
        return left && right;
    }
};