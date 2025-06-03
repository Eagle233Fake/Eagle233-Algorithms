#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int x, y;
        cin >> x >> y;
        int mask = 1;
        int count = 0;
        for (int j = 0; j < 31; j++) {
            int maskX = x & mask;
            int maskY = y & mask;
            if (maskX != maskY) {
                count++;
            }
            mask <<= 1;
        }

        cout << count << endl;
    }
}