#include <bits/stdc++.h>

using namespace std;

vector<int> sub(vector<int> &A, vector<int> &B) {
    int t = 0;
    vector<int> C;
    for (int i = 0; i < A.size() || i < B.size(); i++) {
        if (i < A.size()) {
            t += A[i];
        }
        if (i < B.size()) {
            t -= B[i];
        }

        C.push_back((t + 10) % 10);
        if (t < 0) {
            t = -1;
        } else {
            t = 0;
        }
    }

    while (C.size() > 1 && C.back() == 0) {
        C.pop_back();
    }

    return C;
}

bool cmp(string &a, string &b) {
    if (a.size() == b.size()) {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                return a[i] > b[i];
            }
        }

        return true;
    }

    return a.size() >= b.size();
}

void printVector(vector<int> &C) {
    for (int i = C.size() - 1; i >= 0; i--) {
        cout << C[i];
    }
    cout << endl;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string a, b;
    cin >> a >> b;
    vector<int> A;
    vector<int> B;

    for (int i = a.size() - 1; i >= 0; i--) {
        A.push_back(a[i] - '0');
    }

    for (int i = b.size() - 1; i >= 0; i--) {
        B.push_back(b[i] - '0');
    }

    bool isBigger = cmp(a, b);

    if (isBigger) {
        auto C = sub(A, B);
        printVector(C);
    } else {
        auto C = sub(B, A);
        cout << '-';
        printVector(C);
    }

    return 0;
}
