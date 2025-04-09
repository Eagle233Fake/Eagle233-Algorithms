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
        void traversal(TreeNode *node, vector<int>& v, vector<vector<int>>& paths) {
            v.push_back(node->val);
            if (node->left == nullptr && node->right == nullptr) {
                paths.push_back(v);
            }
            if (node->left != nullptr) {
                traversal(node->left, v, paths);
            }
            if (node->right != nullptr) {
                traversal(node->right, v, paths);
            }
            v.pop_back();
        }
    
        vector<string> binaryTreePaths(TreeNode* root) {
            vector<vector<int>> paths;
            vector<int> v;
            vector<string> s;
            if (root == nullptr) {
                return s;
            }
            traversal(root, v, paths);
            
            for (vector<int> a : paths) {
                string b;
                for (int i = 0; i < a.size() - 1; i++) {
                    b += to_string(a[i]);
                    b += "->";
                }
                b += to_string(a[a.size() - 1]);
                s.push_back(b);
            }
            return s;
        }
    };