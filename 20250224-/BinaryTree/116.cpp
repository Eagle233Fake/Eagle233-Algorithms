/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    public:
        Node* connect(Node* root) {
            queue<Node *> q;
            if (root != nullptr) {
                q.push(root);
                root->next = nullptr;
            }
            
            while (!q.empty()) {
                int size = q.size();
                Node *node1 = nullptr;
                for (int i = 0; i < size; i++) {
                    Node *node2 = q.front();
                    if (node1 != nullptr) {
                        node1->next = node2;
                    }
                    q.pop();
                    if (node2->left != nullptr) {
                        q.push(node2->left);
                    }
                    if (node2->right != nullptr) {
                        q.push(node2->right);
                    }
                    node1 = node2;
                }
                node1->next = nullptr;
            }
            return root;
        }
    };