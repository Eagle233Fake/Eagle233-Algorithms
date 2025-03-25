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
        vector<vector<int>> levelOrder(Node* root) {
            queue<Node *> q;
            vector<vector<int>> r;
            if (root != nullptr) {
                q.push(root);
            }
    
            while (!q.empty()) {
                int size = q.size();
                vector<int> v;
                for (int i = 0 ; i < size; i++) {
                    Node *node = q.front();
                    v.push_back(node->val);
                    q.pop();
                    for (Node *n : node->children) {
                        if (n != nullptr) {
                            q.push(n);
                        }
                    }
                }
                r.push_back(v);
            }
            return r;
        }
    };