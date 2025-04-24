#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int m[N];
int temp[N];

void mergeSort(int l, int r) {
    if (l >= r) {
        return;
    }

    int mid = l + (r - l) / 2;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);

    int i = l, j = mid + 1, k = 0;

    while (i <= mid && j <= r) {
        if (m[i] <= m[j]) {
            temp[k++] = m[i++];
        } else {
            temp[k++] = m[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = m[i++];
    }

    while (j <= r) {
        temp[k++] = m[j++];
    }

    for (i = l, k = 0; i <= r; i++, k++) {
        m[i] = temp[k];
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> m[i];
    }

    mergeSort(0, n - 1);

    for (int i = 0; i < n - 1; i++) {
        cout << m[i] << ' ';
    }

    cout << m[n - 1] << endl;
}