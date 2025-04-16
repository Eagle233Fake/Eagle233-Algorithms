#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int q[N];

void quickSort(int q[], int l, int r) {
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

    quickSort(q, l, j);
    quickSort(q, j + 1, r);
}

int main(void) {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &q[i]);
    }

    quickSort(q, 0, n - 1);

    for (int i = 0; i < n - 1; i++) {
        printf("%d ", q[i]);
    }

    printf("%d\n", q[n - 1]);
}