#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    int count = 0;
    int mask = 1;
    for (int i = 0; i < 32; i ++) {
        if (mask & n) {
            count++;
        }
        mask <<= 1;
    }

    cout << count << endl;
}