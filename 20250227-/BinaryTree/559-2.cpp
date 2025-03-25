/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public:
        int maxDepth(Node* root) {
            if (root == nullptr) {
                return 0;
            }
            vector<int> v;
            for (Node *n : root->children) {
                v.push_back(maxDepth(n));
            }
            int mmax = 0;
            for (int i : v) {
                mmax = max(i, mmax);
            }
            return 1 + mmax;
        }
    };