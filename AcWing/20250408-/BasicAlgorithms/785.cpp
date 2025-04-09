#include <bits/stdc++.h>

using namespace std;

void quickSort(int a[], int l, int r) {
    if (l >= r) {
        return;
    }

    int i = l - 1, j = r + 1;
    int x = a[l + (r - l) / 2];
    while (i < j) {
        do {
            i++;
        } while (a[i] < x);

        do {
            j--;
        } while (a[j] > x);
        if (i < j) {
            swap(a[i], a[j]);
        }
    }

    quickSort(a, l, j);
    quickSort(a, j + 1, r);
}

int main(void) {
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    quickSort(a, 0, n - 1);

    for (int i = 0; i < n - 1; i++) {
        printf("%d ", a[i]);
    }

    printf("%d\n", a[n - 1]);
}