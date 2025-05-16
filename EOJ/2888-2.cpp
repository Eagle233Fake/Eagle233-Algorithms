#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long double n, k, m;
    while (cin >> n >> k >> m) {
        int day = INT_MIN;
        long double prize = 270.0;
        long double sum = 0;
        for (int i = 0; i < 30; i++) {
            sum += n;

            if (sum >= prize) {
                day = i + 1;
                break;
            }
            n *= 1 + m / 100;
            prize *= 1 + k / 100;
        }

        if (day != INT_MIN) {
            cout << day << endl;
        } else {
            cout << "Impossible" << endl;
        }
    }
    return 0;
}
