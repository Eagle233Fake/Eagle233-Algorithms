#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int q[N];

void quickSort(int l, int r) {
    if (l >= r) {
        return;
    }

    int i = l - 1, j = r + 1;
    int mid = q[l + (r - l) / 2];

    while (i < j) {
        do {
            i++;
        } while (q[i] < mid);

        do {
            j--;
        } while (q[j] > mid);

        if (i < j) {
            swap(q[i], q[j]);
        }
    }

    quickSort(l, j);
    quickSort(j + 1, r);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }

    quickSort(0, n - 1);

    for (int i = 0; i < n - 1; i++) {
        cout << q[i] << ' ';
    }

    cout << q[n - 1] << endl;
}