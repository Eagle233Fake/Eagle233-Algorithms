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
        vector<int> traversal(TreeNode *root) {
            if (root == nullptr) {
                return vector<int>{0, 0};
            }
    
            vector<int> left = traversal(root->left);
            vector<int> right = traversal(root->right);
    
            vector<int> dp(2);
            dp[0] = max(left[1], left[0]) + max(right[1], right[0]);
            dp[1] = left[0] + right[0] + root->val;
    
            return dp;
        }
    
        int rob(TreeNode* root) {
            return max(traversal(root)[0], traversal(root)[1]);
        }
    };