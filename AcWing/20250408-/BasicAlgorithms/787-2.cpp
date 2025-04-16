#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int q[N];
int temp[N];

void mergeSort(int q[], int l, int r) {
    if (l >= r) {
        return;
    }

    int mid = l + (r - l) / 2;

    mergeSort(q, l, mid);
    mergeSort(q, mid + 1, r);

    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (q[i] <= q[j]) {
            temp[k++] = q[i++];
        } else {
            temp[k++] = q[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = q[i++];
    }
    while (j <= r) {
        temp[k++] = q[j++];
    }

    for (i = l, k = 0; i <= r; i++, k++) {
        q[i] = temp[k];
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }

    mergeSort(q, 0, n - 1);

    for (int i = 0; i < n - 1; i++) {
        cout << q[i] << " ";
    }
    cout << q[n - 1] << endl;
}