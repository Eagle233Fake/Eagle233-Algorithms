#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int a[N];
int b[N];

void insert(int l, int r, int c) {
    b[l] += c;
    b[r + 1] -= c;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        insert(i, i, a[i]);
    }

    while (m--) {
        int l, r, c;
        cin >> l >> r >> c;
        insert(l, r, c);
    }

    for (int i = 1; i <= n; i++) {
        b[i] += b[i - 1];
    }

    for (int i = 1; i <= n - 1; i++) {
        cout << b[i] << ' ';
    }

    cout << b[n] << endl;

    return 0;
}
