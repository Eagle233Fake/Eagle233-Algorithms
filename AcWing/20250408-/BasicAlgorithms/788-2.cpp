#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int q[N];
int temp[N];

typedef unsigned long long ull;

ull mergeSort(int l, int r) {
    if (l >= r) {
        return 0;
    }

    int mid = l + (r - l) / 2;
    ull sum = 0;
    sum += mergeSort(l, mid);
    sum += mergeSort(mid + 1, r);
    
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (q[i] <= q[j]) {
            temp[k++] = q[i++];
        } else {
            temp[k++] = q[j++];
            sum += mid - i + 1;
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

    return sum;
}

int main(void) {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }
    
    cout << mergeSort(0, n - 1) << endl;
}