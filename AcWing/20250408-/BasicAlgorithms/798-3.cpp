#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
int a[N][N];
int s[N][N];

void insert(int x1, int y1, int x2, int y2, int c) {
    s[x1][y1] += c;
    s[x1][y2 + 1] -= c;
    s[x2 + 1][y1] -= c;
    s[x2 + 1][y2 + 1] += c;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            insert(i, j, i, j, a[i][j]);
        }
    }

    while (q--) {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(x1, y1, x2, y2, c);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < m; j++) {
            cout << s[i][j] << ' ';
        }
        cout << s[i][m] << endl;
    }

    return 0;
}
