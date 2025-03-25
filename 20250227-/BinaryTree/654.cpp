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
        TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
            int maxNum = INT_MIN, maxNumIndex;
            if (nums.size() == 0) {
                return nullptr;
            }
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] > maxNum) {
                    maxNum = nums[i];
                    maxNumIndex = i;
                }
            }
    
            TreeNode *root = new TreeNode(maxNum);
            
            vector<int> leftNums(nums.begin(), nums.begin() + maxNumIndex);
            vector<int> rightNums(nums.begin() + maxNumIndex + 1, nums.end());
    
            root->left = constructMaximumBinaryTree(leftNums);
            root->right = constructMaximumBinaryTree(rightNums);
            return root;
        }
    };