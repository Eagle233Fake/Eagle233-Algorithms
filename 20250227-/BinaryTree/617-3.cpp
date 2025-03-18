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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr) {
            return root2;
        }
        if (root2 == nullptr) {
            return root1;
        }

        queue<TreeNode *> q;
        q.push(root1);
        q.push(root2);
        while (!q.empty()) {
            TreeNode *node1 = q.front();
            q.pop();
            TreeNode *node2 = q.front();
            q.pop();

            node1->val += node2->val;

            if (node1->left != nullptr && node2->left != nullptr) {
                q.push(node1->left);
                q.push(node2->left);
            }

            if (node1->right != nullptr && node2->right != nullptr) {
                q.push(node1->right);
                q.push(node2->right);
            }

            if (node1->left == nullptr && node2->left != nullptr) {
                node1->left = node2->left;
            }
            if (node1->right == nullptr && node2->right != nullptr) {
                node1->right = node2->right;
            }
        }

        return root1;
    }
};