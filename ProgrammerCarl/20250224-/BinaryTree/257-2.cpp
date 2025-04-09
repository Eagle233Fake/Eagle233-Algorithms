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
        void traversal(TreeNode *node, string s, vector<string>& paths) {
            s += to_string(node->val);
            if (node->left == nullptr && node->right == nullptr) {
                paths.push_back(s);
            }
            if (node->left != nullptr) {
                traversal(node->left, s + "->", paths);
            }
            if (node->right != nullptr) {
                traversal(node->right, s + "->", paths);
            }
        }
    
        vector<string> binaryTreePaths(TreeNode* root) {
            vector<string> paths;
            if (root == nullptr) {
                return paths;
            }
            string s;
            traversal(root, s, paths);
            return paths;
        }
    };