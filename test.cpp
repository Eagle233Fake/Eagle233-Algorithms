#include <bits/stdc++.h>
using namespace std;

class UnionFind {
public:
    UnionFind(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

private:
    vector<int> parent;
    vector<int> rank;
};

int main() {
    int n, m, p;
    cin >> n >> m >> p;

    UnionFind uf(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        uf.unionSets(a, b);
    }

    for (int i = 0; i < p; i++) {
        int a, b;
        cin >> a >> b;
        if (uf.find(a) == uf.find(b)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
