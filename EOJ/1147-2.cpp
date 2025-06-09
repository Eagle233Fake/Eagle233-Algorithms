#include <bits/stdc++.h>

using namespace std;

vector<char> trans(int N, int R) {
    vector<char> C;
    while (N) {
        C.push_back(N % R);
        N /= R;
    }

    for (int i = 0; i < C.size(); i++) {
        if (C[i] < 10) {
            C[i] += '0';
        } else {
            C[i] += 'A' - 10;
        }
    }

    return C;
}

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int N, R;
        cin >> N >> R;
        
        bool isNeg = false;
        if (N < 0) {
            isNeg = true;
            N = -N;
        }
        auto C = trans(N, R);
        if (isNeg) {
            cout << '-';
        }
        for (int i = C.size() - 1; i >= 0; i--) {
            cout << C[i];
        }
        cout << endl;
    }
}