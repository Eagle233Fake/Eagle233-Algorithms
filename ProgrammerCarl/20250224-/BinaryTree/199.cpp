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
        vector<int> rightSideView(TreeNode* root) {
            vector<int> v;
            queue<TreeNode *> q;
            if (root != nullptr) {
                q.push(root);
            }
            while (!q.empty()) {
                int size = q.size();
                for (int i = 0; i < size; i++) {
                    TreeNode *node = q.front();
                    q.pop();
                    if (i == size - 1) {
                        v.push_back(node->val);
                    }
                    if (node->left != nullptr) {
                        q.push(node->left);
                    }
                    if (node->right != nullptr) {
                        q.push(node->right);
                    }
                }
            }
            return v;
        }
    };