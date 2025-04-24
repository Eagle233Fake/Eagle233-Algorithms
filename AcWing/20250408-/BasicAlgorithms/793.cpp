#include <bits/stdc++.h>

using namespace std;

vector<int> mul(vector<int> &A, int b) {
    int t = 0;
    vector<int> C;
    for (int i = 0; i < A.size() || t; i++) {
        if (i < A.size()) {
            t += A[i] * b;
        }
        C.push_back(t % 10);
        t /= 10;
    }

    return C;
}

int main(void) {
    string a;
    int b;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> b;

    vector<int> A;
    for (int i = a.size() - 1; i >= 0; i--) {
        A.push_back(a[i] - '0');
    }

    auto C = mul(A, b);

    if (b == 0 || a == "0") {
        cout << 0 << endl;
        return 0;
    }

    for (int i = C.size() - 1; i >= 0; i--) {
        cout << C[i];
    }

    cout << endl;
}