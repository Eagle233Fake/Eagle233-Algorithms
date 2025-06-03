#include <bits/stdc++.h>

using namespace std;

vector<char> trans(int N, int R) {
    int t = 0;
    vector<char> C;
    
    while (N) {
        C.push_back(N % R);
        N /= R;
    }

    for (char & c : C) {
        if (c >= 10) {
            c += 'A' - 10;
            continue;
        }
        c += '0';
    }

    return C;
}

void print(vector<char> &C) {
    for (int i = C.size() - 1; i >= 0; i--) {
        cout << C[i];
    }
    cout << endl;
}

int main(void) {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N, R;
        cin >> N >> R;
        if (N == 0) {
            cout << 0 << endl;
        }

        bool isNeg = false;
        if (N < 0) {
            isNeg = true;
            N = -N;
        }

        auto C = trans(N, R);
        if (isNeg) {
            cout << '-';
        }
        print(C);
    }
}