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
        vector<int> v;
        vector<vector<int>> vv;
        void traversal(TreeNode *node, int sum) {
            if (node->left == nullptr && node->right == nullptr && sum == 0) {
                vv.push_back(v);
            }
            if (node->left != nullptr) {
                v.push_back(node->left->val);
                traversal(node->left, sum - node->left->val);
                v.pop_back();
            }
            if (node->right != nullptr) {
                v.push_back(node->right->val);
                traversal(node->right, sum - node->right->val);
                v.pop_back();
            }
        }
    
        vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
            if (root == nullptr) {
                return vv;
            }
            v.push_back(root->val);
            traversal(root, targetSum - root->val);
            return vv;
        }
    };