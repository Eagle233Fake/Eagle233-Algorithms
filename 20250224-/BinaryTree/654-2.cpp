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
        TreeNode *traversal(vector<int> &nums, int left, int right) {
            if (left >= right) {
                return nullptr;
            }
            int maxNum = INT_MIN;
            int index;
            for (int i = left; i < right; i++) {
                if (nums[i] > maxNum) {
                    index = i;
                    maxNum = nums[i];
                }
            }
    
            TreeNode *node = new TreeNode(maxNum);
            node->left = traversal(nums, left, index);
            node->right = traversal(nums, index + 1, right);
            return node;
        }
        
        TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
            return traversal(nums, 0, nums.size());
        }
    };