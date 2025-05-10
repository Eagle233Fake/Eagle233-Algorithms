#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
    int height;
    Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

int height(Node* n) {
    return n ? n->height : 0;
}

void updateHeight(Node* n) {
    n->height = max(height(n->left), height(n->right)) + 1;
}

int balanceFactor(Node* n) {
    return height(n->left) - height(n->right);
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    updateHeight(y);
    updateHeight(x);
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    updateHeight(x);
    updateHeight(y);
    return y;
}

Node* insert(Node* node, int key) {
    if (!node)
        return new Node(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else 
        node->right = insert(node->right, key);

    updateHeight(node);

    int bf = balanceFactor(node);

    if (bf > 1 && key < node->left->key)
        return rightRotate(node);
    if (bf < -1 && key > node->right->key)
        return leftRotate(node);
    if (bf > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (bf < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    Node* root = nullptr;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }
    if (root)
        cout << root->key << "\n";
    return 0;
}
