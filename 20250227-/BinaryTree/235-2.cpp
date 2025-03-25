/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 class Solution {
    public:
        TreeNode* traversal(TreeNode* root, TreeNode* p, TreeNode* q) {
            if (root->val < p->val) {
                return traversal(root->right, p, q);
            }
    
            if (root->val > q->val) {
                return traversal(root->left, p, q);
            }
            
            return root;
        }
    
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if (p->val > q->val) {
                return traversal(root, q, p);
            } else {
                return traversal(root, p, q);
            }
        }
    };