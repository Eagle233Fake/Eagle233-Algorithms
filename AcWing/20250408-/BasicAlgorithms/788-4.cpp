#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int m[N];
int temp[N];

unsigned long long mergeSort(int l, int r) {
    if (l >= r) {
        return 0;
    }

    unsigned long long sum = 0;
    int mid = l + (r - l) / 2;
    sum += mergeSort(l, mid);
    sum += mergeSort(mid + 1, r);

    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (m[i] <= m[j]) {
            temp[k++] = m[i++];
        } else {
            sum += mid - i + 1;
            temp[k++] = m[j++];
            
        }
    }

    while (i <= mid) {
        temp[k++] = m[i++];
    }
    while (j <= r) {
        temp[k++] = m[j++];
    }

    for (int i = l, k = 0; i <= r; i++, k++) {
        m[i] = temp[k];
    }

    return sum;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m[i];
    }

    cout << mergeSort(0, n - 1) << endl;
}