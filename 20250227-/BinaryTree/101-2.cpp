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
            queue<TreeNode *> q;
            if (root != nullptr) {
                q.push(root->left);
                q.push(root->right);
            } else {
                return true;
            }
            
            while (!q.empty()) {
                TreeNode *leftNode = q.front();
                q.pop();
                TreeNode *rightNode = q.front();
                q.pop();
                
                if (leftNode == nullptr && rightNode != nullptr) {
                    return false;
                } else if (leftNode == nullptr && rightNode == nullptr) {
                    continue; // 不能直接 return
                } else if (leftNode != nullptr && rightNode == nullptr) {
                    return false;
                } else if (leftNode->val != rightNode->val) {
                    return false;
                }
    
                q.push(leftNode->left);
                q.push(rightNode->right);
                q.push(leftNode->right);
                q.push(rightNode->left);
            }
            return true;
        }
    };