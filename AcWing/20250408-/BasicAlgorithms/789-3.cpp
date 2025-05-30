#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int a[N];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    while (q--) {
        int x;
        cin >> x;
        int l = 0, r = n - 1;
        int mid;

        while (l < r) {
            mid = l + (r - l) / 2; // mid写在while里面
            if (a[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        if (a[l] != x) {
            cout << "-1 -1" << endl;
            continue;
        }

        cout << l << " ";
        l = 0, r = n - 1;

        while (l < r) {
            mid = l + (r - l + 1) / 2; 
            if (a[mid] <= x) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        
        cout << r << endl;
    }

    return 0;
}