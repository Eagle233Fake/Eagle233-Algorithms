#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

int main(void) {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        ull res = 0;

        for (int w = 0; w * 4 <= n; w++) {
            for (int x = 0; x * 3 <= n; x++) {
                for (int y = 0; y * 2 <= n; y++) {
                    int sum = w * 4 + x * 3 + y * 2;
                    if (n >= sum) {
                        res++;
                    }
                }
            }
        }

        cout << res << endl;
    }
}