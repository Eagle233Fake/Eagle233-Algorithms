#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n, m;
    int count[100055] = {0};
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        count[a]++;
        count[b]++;
        if (count[a] == m) {
            cout << a;
            return 0;
        }
        if (count[b] == m) {
            cout << b;
            return 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (count[i] == n - 1) {
            cout << i;
            return 0;
        }
    }
}
