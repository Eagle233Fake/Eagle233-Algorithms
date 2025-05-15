#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int A[N][N];
int B[N][N];

void insert(int x1, int y1, int x2, int y2, int c) {
    B[x1][y1] += c;
    B[x2 + 1][y1] -= c;
    B[x1][y2 + 1] -= c;
    B[x2 + 1][y2 + 1] += c;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> A[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            insert(i, j, i, j, A[i][j]);
        }
    }

    while (q--) {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(x1, y1, x2, y2, c);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            B[i][j] += B[i - 1][j] + B[i][j - 1] - B[i - 1][j - 1];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < m; j++) {
            cout << B[i][j] << ' ';
        }

        cout << B[i][m] << endl;
    }
    return 0;
}
