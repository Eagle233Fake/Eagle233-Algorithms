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
        vector<vector<int>> levelOrderBottom(TreeNode* root) {
            vector<vector<int>> result;
            queue<TreeNode *> q;
            if (root != nullptr) {
                q.push(root);
            }
            while (!q.empty()) {
                int size = q.size();
                vector<int> v;
                while (size--) {
                    TreeNode *node = q.front();
                    v.push_back(node->val);
                    q.pop();
                    if (node->left != nullptr) {
                        q.push(node->left);
                    }
                    if (node->right != nullptr) {
                        q.push(node->right);
                    }
                }
                result.push_back(v);
            }
            reverse(result.begin(), result.end());
            return result;
        }
    };