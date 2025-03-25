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
        TreeNode* traversal(vector<int>& inorder, vector<int>& postorder) {
            // root
            if (inorder.size() == 0) {
                return nullptr;
            }
            int rootVal = postorder[postorder.size() - 1];
            TreeNode *root = new TreeNode(rootVal);
            if (inorder.size() == 1) {
                return root;
            }
            int index = 0;
    
            // Find value
            for (index = 0; index < inorder.size(); index++) {
                if (inorder[index] == rootVal) {
                    break;
                }
            }
    
            // postorder
            vector<int> leftPostorder(postorder.begin(), postorder.begin() + index);
            vector<int> rightPostorder(postorder.begin() + index, postorder.end() - 1);
    
            // inorder
            vector<int> leftInorder(inorder.begin(), inorder.begin() + index);
            vector<int> rightInorder(inorder.begin() + index + 1, inorder.end());
    
            // return
            root->left = traversal(leftInorder, leftPostorder);
            root->right = traversal(rightInorder, rightPostorder);
            return root;
        }
    
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            return traversal(inorder, postorder);
        }
    };