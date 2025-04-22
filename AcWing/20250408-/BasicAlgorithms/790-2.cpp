#include <bits/stdc++.h>

using namespace std;

int main(void) {
    long double l = -10000, r = 10000;
    long double a;
    cin >> a;
    ios::sync_with_stdio(false);
    cin.tie(0);
  
    while (r - l > 10e-8) {
        long double mid = l + (r - l) / 2;
        if (a > mid * mid * mid) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << fixed << setprecision(6) << l << endl;
}