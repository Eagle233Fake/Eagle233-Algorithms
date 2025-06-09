#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int count = 0;
        int mask = 1;
        for (int i = 0; i < 31; i++) {
            if ((mask & a) != (mask & b)) {
                count++;
            }
            mask <<= 1;
        }

        cout << count << endl;
    }
}