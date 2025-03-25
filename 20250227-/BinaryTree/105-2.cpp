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
        TreeNode *traversal(vector<int>& preorder, vector<int>& inorder, int preorderLeft, int preorderRight, int inorderLeft, int inorderRight) {
            if (preorderLeft >= preorderRight) {
                return nullptr;
            }
    
            int nodeVal = preorder[preorderLeft];
            TreeNode *node = new TreeNode(nodeVal);
    
            if (inorderRight - inorderLeft == 1) {
                return node;
            }
            int index;
            for (index = inorderLeft; index < inorderRight; index++) {
                if (inorder[index] == nodeVal) {
                    break;
                }
            }
    
            node->left = traversal(preorder, inorder, preorderLeft + 1, preorderLeft + 1 + index - inorderLeft, inorderLeft, index);
            node->right = traversal(preorder, inorder, preorderLeft + 1 + index - inorderLeft, preorderRight, index + 1, inorderRight);
            return node;
        }
    
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            return traversal(preorder, inorder, 0, preorder.size(), 0, inorder.size());
        }
    };