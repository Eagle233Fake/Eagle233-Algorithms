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
            }
    
            while (!q.empty()) {
                int size = q.size();
                Node *node, *preNode = nullptr;
                for (int i = 0; i < size; i++) {
                    node = q.front();
                    q.pop();
                    if (preNode != nullptr) {
                        preNode->next = node;
                    }
                    if (node->left != nullptr) {
                        q.push(node->left);
                    }
                    if (node->right != nullptr) {
                        q.push(node->right);
                    }
                    preNode = node;
                }
                node->next = NULL;
            }
            return root;
        }
    };