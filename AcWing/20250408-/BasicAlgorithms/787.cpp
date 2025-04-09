#include <bits/stdc++.h>

using namespace std;

const int N = 100000;

int q[N];
int temp[N];

void mergeSort(int l, int r) {
    if (l >= r) return;
    
    int mid = l + (r - l) / 2;
    
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    
    int i = l, j = mid + 1;
    int k = 0;
    while (i <= mid && j <= r) {
        if (q[i] <= q[j]) {
            temp[k] = q[i];
            k++;
            i++;
        } else {
            temp[k] = q[j];
            k++;
            j++;
        }
    }
    
    
    while (i <= mid) {
        temp[k] = q[i];
        k++;
        i++;
    }

    while (j <= r) {
        temp[k] = q[j];
        k++;
        j++;
    }
    
    for (i = l, k = 0; i <= r; i++, k++) {
        q[i] = temp[k];
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &q[i]);
    }
    
    mergeSort(0, n - 1);
    
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", q[i]);
    }
    printf("%d\n", q[n - 1]);
}