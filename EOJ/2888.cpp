#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long double n, k, m;
    while (cin >> n >> k >> m) {
        long double sum = 0;
        long double house = 270;
        bool isGot = false;
        
        for (int i = 1; i <= 30; i++) {
            sum += n;
            if (sum >= house) {
                cout << i << endl;
                isGot = true;
                break;
            }

            n *= 1 + m / 100;
            house *= 1 + k / 100;
        }
        if (!isGot) {
            cout << "Impossible" << endl;
        }
    }

    return 0;
}
