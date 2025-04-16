#include <bits/stdc++.h>

using namespace std;

int main(void) {
    long double n;
    cin >> n;

    long double l = -10000;
    long double r = 10000;

    while (r - l > 10e-8) {
        long double mid = l + (r - l) / 2;
        if (mid * mid * mid <= n) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << fixed << setprecision(6) << l;
}