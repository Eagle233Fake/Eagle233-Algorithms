#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int q[N];

int quickSort(int l, int r, int k) {
    if (l >= r) {
        return q[l]; // 返回的是数字不是下标
    }

    int i = l - 1;
    int j = r + 1;
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

    if (k > j - l + 1) {
        return quickSort(j + 1, r, k - j + l - 1);
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