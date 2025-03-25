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
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            if (preorder.size() == 0) {
                return nullptr;
            }
            int rootVal = preorder[0];
            TreeNode *root = new TreeNode(rootVal);
            if (preorder.size() == 1) {
                return root;
            }
    
            int index;
            for (index = 0; index < preorder.size(); index++) {
                if (inorder[index] == rootVal) {
                    break;
                }
            }
    
            vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + index + 1);
            vector<int> rightPreorder(preorder.begin() + index + 1, preorder.end());
            vector<int> leftInorder(inorder.begin(), inorder.begin() + index);
            vector<int> rightInorder(inorder.begin() + index + 1, inorder.end());
    
            root->left = buildTree(leftPreorder, leftInorder);
            root->right = buildTree(rightPreorder, rightInorder);
            return root;
        }
    };