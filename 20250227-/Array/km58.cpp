#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    for (int i = 1; i < n; i++) {
        v[i] += v[i - 1];
    }

    int a, b;
    while (cin >> a >> b) {
        if (a == 0) {
            cout << v[b] << endl;
        } else {
            cout << v[b] - v[a - 1] << endl;
        }
    }
}