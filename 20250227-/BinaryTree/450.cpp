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
        TreeNode* deleteNode(TreeNode* root, int key) {
            if (root == nullptr) {
                return root;
            }
            if (root->val == key) {
                if (root->right == nullptr && root->left == nullptr) {
                    delete root;
                    return nullptr;
                } else if (root->right == nullptr && root->left != nullptr) {
                    TreeNode *rootNode = root->left;
                    delete root;
                    return rootNode;
                } else if (root->right != nullptr && root->left == nullptr) {
                    TreeNode *rootNode = root->right;
                    delete root;
                    return rootNode;
                } else {
                    TreeNode *node = root->right;
                    while (node->left != nullptr) {
                        node = node->left;
                    }
                    node->left = root->left;
                    TreeNode *rootNode = root->right;
                    delete root;
                    return rootNode;
                }
            }
    
            if (root->val < key) {
                root->right = deleteNode(root->right, key);
            } else {
                root->left = deleteNode(root->left, key);
            }
            return root;
        }
    };