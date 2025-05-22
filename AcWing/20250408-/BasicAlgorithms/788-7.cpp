#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

const int N = 100010;

int a[N];
int temp[N];

ull mergeSelect(int l, int r) {
    if (l >= r) {
        return 0;
    }

    ull sum = 0;
    int mid = l + (r - l) / 2;
    sum += mergeSelect(l, mid);
    sum += mergeSelect(mid + 1, r);

    int i = l, j = mid + 1;
    int k = 0;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
            sum += mid - i + 1; 
        }
    }

    while (i <= mid) {
        temp[k++] = a[i++];
    }

    while (j <= r) {
        temp[k++] = a[j++];
    }

    for (k = 0, i = l; i <= r; i++, k++) {
        a[i] = temp[k];
    }

    return sum;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << mergeSelect(0, n - 1) << endl;
    return 0;
}
