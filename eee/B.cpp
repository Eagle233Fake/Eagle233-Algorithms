#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

struct Node {
    Node *children[ALPHABET_SIZE];
    Node *fail;
    int cnt;
    Node() {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            children[i] = nullptr;
        }
        fail = nullptr;
        cnt = 0;
    }
};

Node *root;

void insert(string word) {
    Node *p = root;
    for (char c : word) {
        int idx = c - 'a';
        if (p->children[idx] == nullptr) {
            p->children[idx] = new Node();
        }
        p = p->children[idx];
    }
    p->cnt++;
}

void build() {
    queue<Node*> q;
    root->fail = root;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i] != nullptr) {
            root->children[i]->fail = root;
            q.push(root->children[i]);
        } else {
            root->children[i] = root;
        }
    }

    while (!q.empty()) {
        Node *u = q.front(); 
        q.pop();
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (u->children[i] != nullptr) {
                Node *v = u->children[i];
                v->fail = u->fail->children[i];
                q.push(v);
            } else {
                u->children[i] = u->fail->children[i];
            }
        }
    }
}

long long query(string article) {
    long long ans = 0;
    Node *p = root;
    for (char c : article) {
        int idx = c - 'a';
        p = p->children[idx];
        Node *temp = p;
        while (temp != root) {
            ans += temp->cnt;
            temp = temp->fail;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    root = new Node();
    string word;
    for (int i = 0; i < n; i++) {
        cin >> word;
        insert(word);
    }
    build();
    string article;
    cin >> article;
    cout << query(article) << endl;
    return 0;
}