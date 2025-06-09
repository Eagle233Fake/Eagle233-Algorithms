#include <bits/stdc++.h>

using namespace std;

vector<int> mul(vector<int> &A, vector<int> &B) {
    vector<int> C(A.size() + B.size(), 0);
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B.size(); j++) {
            C[i + j] += A[i] * B[j];
        }
    }

    while (C.size() > 0 && C.back() == 0) {
        C.pop_back();
    }
    
    return C;
}

vector<int> trans(string &s) {
    vector<int> A(52, 0);
    
    while (!s.empty()) {
        if (s.find("x") == string::npos) {
            A[0] = stoi(s);
            break;
        } else {
            int times = 0;
            int index = 0;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == 'x') {
                    index = stoi(s.substr(0, i));
                    s = s.substr(i + 1, s.size() - (i + 1));
                    break;
                }
            }

            if (s[0] != '^') {
                A[1] = index;
            } else {
                times = s[1] - '0';
                A[times] = index;
                s = s.substr(2, s.size() - 2);
            }
        }
    }

    return A;
}

int main(void) {
    string a, b;
    while (cin >> a >> b) {
        vector<int> A = trans(a);
        vector<int> B = trans(b);

        auto C = mul(A, B);

        for (int i = C.size() - 1; i > 0; i++) {
            cout << C[i] << ' ';
        }
        cout << C[0] << endl;
    }
}