#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100 + 5;
vector<int> G[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int a, x, y;
    for (int i = 0; i < m; i++) {
        cin >> a >> x >> y;
        if (a == 0) {
            G[x].push_back(y);
        } else {
            G[x].push_back(y);
            G[y].push_back(x);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << i << ":";
        for (int j = (int)G[i].size() - 1; j >= 0; j--) {
            cout << " " << G[i][j];
        }
        cout << "\n";
    }

    return 0;
}
