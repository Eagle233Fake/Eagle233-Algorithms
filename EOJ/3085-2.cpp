#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    int mask = 1;
    int count = 0;

    for (int i = 0; i < 31; i++) {
        if (n & mask) {
            count++;
        }
        mask <<= 1;
    }

    cout << count << endl;
}   