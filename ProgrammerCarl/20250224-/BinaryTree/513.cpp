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
        int findBottomLeftValue(TreeNode* root) {
            queue<TreeNode *> q;
            if (root != nullptr) {
                q.push(root);
            }
    
            int val = root->val;
            while (!q.empty()) {
                int size = q.size();
                for (int i = 0; i < size; i++) {
                    TreeNode *node = q.front();
                    q.pop();
                    if (i == 0 && node->left == nullptr && node->right == nullptr) {
                        val = node->val;
                    }
                    if (node->left != nullptr) {
                        q.push(node->left);
                    }
                    if (node->right != nullptr) {
                        q.push(node->right);
                    }
                }
            }
            return val;
        }
    };