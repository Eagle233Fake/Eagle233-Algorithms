#include <bits/stdc++.h>

using namespace std;

int quickSort(vector<int> &a, int l, int r, int k) {
    if (l == r) {
        return a[l];
    }
    
    int i = l - 1;
    int j = r + 1;
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
    
    int lenL = j - l + 1;
    if (k <= lenL) {
        return quickSort(a, l, j, k);
    }
    return quickSort(a, j + 1, r, k - lenL);
}

int main(void) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    cout << quickSort(a, 0, n - 1, k) << endl;
}