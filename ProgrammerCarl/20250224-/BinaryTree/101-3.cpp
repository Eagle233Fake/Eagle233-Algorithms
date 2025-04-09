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
        bool isSymmetric(TreeNode* root) {
            stack<TreeNode *> s;
            if (root != nullptr) {
                s.push(root->left);
                s.push(root->right);
            }
    
            while (!s.empty()) {
                TreeNode *leftNode = s.top();
                s.pop();
                TreeNode *rightNode = s.top();
                s.pop();
    
                if (leftNode != nullptr && rightNode == nullptr) {
                    return false;
                } else if (leftNode == nullptr && rightNode != nullptr) {
                    return false;
                } else if (leftNode == nullptr && rightNode == nullptr) {
                    continue;
                } else if (leftNode->val != rightNode->val) {
                    return false;
                }
    
                s.push(leftNode->left);
                s.push(rightNode->right);
                s.push(rightNode->left);
                s.push(leftNode->right);
            }
            return true;
        }
    };