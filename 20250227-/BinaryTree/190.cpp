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
        int result = INT_MAX;
        void traversal(TreeNode *cur) {
            if (cur == nullptr) {
                return;
            }
            traversal(cur->left);
            if (pre != nullptr) {
                result = min(abs(cur->val - pre->val) , result);
            }
            pre = cur;
            traversal(cur->right);
        }
    
        int getMinimumDifference(TreeNode* root) {
            traversal(root);
            return result;
        }
    };