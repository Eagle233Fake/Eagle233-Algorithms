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
        int count = 0;
    
        int traversal(TreeNode *root) {
            if (root == nullptr) {
                return 2;
            }
    
            int left = traversal(root->left);
            int right = traversal(root->right);
    
            if (left == 2 && right == 2) {
                return 0;
            }
            if (left == 0 || right == 0) {
                count++;
                return 1;
            }
            if (left == 1 || right == 1) {
                return 2;
            }
            return -1;
        }
    
        int minCameraCover(TreeNode* root) {
            if (traversal(root) == 0) {
                count++;
            }
            return count;
        }
    };