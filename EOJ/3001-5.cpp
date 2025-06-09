#include <bits/stdc++.h>

using namespace std;

vector<int> mul(vector<int> &A, vector<int> &B) {
    vector<int> C(A.size() + B.size(), 0);
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B.size(); j++) {
            C[i + j] += A[i] * B[j];
        }
    }

    for (int i = 0; i < C.size() - 1; i++) {
        C[i + 1] += C[i] / 10;
        C[i] %= 10;
    }

    while (C.size() > 1 && C.back() == 0) {
        C.pop_back();
    }

    return C;
}

void solve(void) {
    int a, n;
    cin >> a >> n;
    if (n == 0) {
        cout << 1 << endl;
        return;
    }

    vector<int> A(1, a);
    vector<int> B(1, 1);

    auto C = mul(A, B);
    n--;
    while (n--) {
        C = mul(A, C);
    }

    for (int i = C.size() - 1; i >= 0; i--) {
        cout << C[i];
    }
    cout << endl;
}

int main(void) {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "case #" << i << ':' << endl;
        solve();
    }
}