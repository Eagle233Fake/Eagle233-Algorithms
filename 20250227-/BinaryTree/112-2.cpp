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
        bool hasPathSum(TreeNode* root, int targetSum) {
            if (root == nullptr) {
                return false;
            }
    
            stack<pair<TreeNode *, int>> st;
            if (root != nullptr) {
                st.push(pair<TreeNode *, int>(root, root->val));
            }
    
            while (!st.empty()) {
                pair<TreeNode *, int> p = st.top();
                st.pop();
                if (p.first->left == nullptr && p.first->right == nullptr && p.second == targetSum) {
                    return true;
                }
                if (p.first->left != nullptr) {
                    st.push(pair<TreeNode *, int>(p.first->left, p.second + p.first->left->val));
                }
                if (p.first->right != nullptr) {
                    st.push(pair<TreeNode *, int>(p.first->right, p.second + p.first->right->val));
                }
            }
            return false;
        }
    };