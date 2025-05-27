#include <bits/stdc++.h>

using namespace std;

int bitLow(int x) {
    return x & (-x);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (auto i : a) {
        int count = 0;
        while (i) {
            i -= bitLow(i);
            count++;
        }
        cout << count << ' ';
    }
    cout << endl;

    return 0;
}
