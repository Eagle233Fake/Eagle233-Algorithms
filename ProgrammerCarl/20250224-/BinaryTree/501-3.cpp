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
        int maxCount;
        int count = 0;
        TreeNode *pre = nullptr;
        void traversal(TreeNode *root) {
            if (root == nullptr) {
                return;
            }
            traversal(root->left);
            if (pre == nullptr) {
                count = 1;
            } else if (pre->val == root->val) {
                count++;
            } else if (pre->val != root->val) {
                count = 1;
            }
            if (maxCount == count) {
                v.push_back(root->val);
            }
            if (count > maxCount) {
                v.clear();
                maxCount = count;
                v.push_back(root->val);
            }
            pre = root;
            traversal(root->right);
        }
    
        vector<int> findMode(TreeNode* root) {
            traversal(root);
            return v;
        }
    };