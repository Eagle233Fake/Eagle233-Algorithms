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
    string a;
    int n;
    cin >> a >> n;

    if (n == 0) {
        cout << 1;
        return;
    }
    if (n == 1) {
        cout << a;
        return;
    }

    n--;
    vector<int> A;
    for (int i = a.size() - 1; i >= 0; i--) {
        A.push_back(a[i] - '0');
    }

    vector<int> B(1, 1);

    auto C = mul(B, A);
    while (n--) {
        C = mul(C, A);
    }

    for (int i = C.size() - 1; i >= 0; i--) {
        cout << C[i];
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cout << "case #" << i << ':' << endl;
        solve();
        cout << endl;
    }

    return 0;
}