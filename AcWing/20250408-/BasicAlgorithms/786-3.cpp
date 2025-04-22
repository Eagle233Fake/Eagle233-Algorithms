#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int q[N];

int quickSort(int l, int r, int k) {
    if (l == r) {
        return q[l];
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
    
    if (j - l + 1 < k) {
        return quickSort(j + 1, r, k - (j - l + 1));
    }
    return quickSort(l, j, k);
    
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }

    cout << quickSort(0, n - 1, k) << endl;
}