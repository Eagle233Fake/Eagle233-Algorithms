#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
int A[N];
int B[N];

void insert(int l, int r, int c) {
    B[l] += c;
    B[r + 1] -= c;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= n; i++) {
        insert(i, i, A[i]);
    }

    while (m--) {
        int l, r, c;
        cin >> l >> r >> c;
        insert(l, r, c);
    }

    for (int i = 1; i <= n; i++) {
        B[i] += B[i - 1];
    }

    for (int i = 1; i < n; i++) {
        cout << B[i] << ' ';
    }

    cout << B[n] << endl;

    return 0;
}
