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
        TreeNode *traversal(vector<int>& inorder, vector<int>& postorder, int inorderLeft, int inorderRight, int postorderLeft, int postorderRight) {
            if (inorderLeft >= inorderRight) {
                return nullptr;
            }
            int rootVal = postorder[postorderRight - 1];
            TreeNode *root = new TreeNode(rootVal);
            if (inorderRight - inorderLeft == 1) {
                return root;
            }
            int i = 0;
            for (i = inorderLeft; i < inorderRight; i++) {
                if (inorder[i] == rootVal) {
                    break;
                }
            }
    
            root->left = traversal(inorder, postorder, inorderLeft, i, postorderLeft, postorderLeft + i - inorderLeft);
            root->right = traversal(inorder, postorder, i + 1, inorderRight, postorderLeft + i - inorderLeft, postorderRight - 1);
            return root;
        }
    
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            return traversal(inorder, postorder, 0, inorder.size(), 0, postorder.size());
        }
    };