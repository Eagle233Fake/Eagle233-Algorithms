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
        int countNodes(TreeNode* root) {
            queue<TreeNode *> q;
            int n = 0;
            if (root != nullptr) {
                q.push(root);
                n++;
            }
    
            
            while(!q.empty()) {
                int size = q.size();
                for (int i = 0; i < n; i++) {
                    TreeNode *node = q.front();
                    q.pop();
                    if (node->left != nullptr) {
                        n++;
                        q.push(node->left);
                    }
                    if (node->right != nullptr) {
                        n++;
                        q.push(node->right);
                    }
                }
            }
    
            return n;
        }
    };