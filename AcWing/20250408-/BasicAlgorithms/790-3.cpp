#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double n;
    cin >> n;

    double l = -10000, r = 10000;
    double mid;
    while (r - l > 1e-8) {
        mid = l + (r - l) / 2;
        if (mid * mid * mid <= n) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << fixed << setprecision(6) << r << endl;
}