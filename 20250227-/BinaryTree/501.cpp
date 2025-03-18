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
        unordered_map<int, int> m;
    
        void traversal(TreeNode *node) {
            if (node == nullptr) {
                return;
            }
            traversal(node->left);
            m[node->val]++;
            traversal(node->right);
        }
    
        bool static cmp(const pair<int, int> &p1, const pair<int, int> &p2) {
            return p1.second > p2.second;
        }
    
        vector<int> findMode(TreeNode* root) {
            traversal(root);
            vector<pair<int, int>> v(m.begin(), m.end());
            sort(v.begin(), v.end(), cmp);
    
            int maxTimes = v[0].second;
            vector<int> vv;
            for (pair<int, int> pp : v) {
                if (pp.second == maxTimes) {
                    vv.push_back(pp.first);
                }
            }
            return vv;
        }
    };