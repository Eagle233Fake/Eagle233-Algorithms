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
            int depth = 0;
            queue<Node *> q;
            if (root != nullptr) {
                q.push(root);
            }
    
            while (!q.empty()) {
                int size = q.size();
                depth++;
                for (int i = 0; i < size; i++) {
                    Node *node = q.front();
                    q.pop();
                    for (Node *n : node->children) {
                        if (n != nullptr) {
                            q.push(n);
                        }
                    }
                }
            }
    
            return depth;
        }
    };