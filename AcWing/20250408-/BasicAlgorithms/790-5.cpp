#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double n;
    double l = -1e4;
    double r = 1e4;
    cin >> n;

    while (r - l > 1e-8) {
        double mid = l + (r - l) / 2;
        if (mid * mid * mid < n) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << fixed << setprecision(6) << l << endl;

    return 0;
}
