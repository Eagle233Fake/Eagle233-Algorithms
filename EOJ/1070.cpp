#include <bits/stdc++.h>

using namespace std;

vector<int> mul(string &a, string &b) {
    vector<int> C(a.size() + b.size(), 0);
    vector<int> A;
    vector<int> B;
    for (int i = a.size() - 1; i >= 0; i--) {
        A.push_back(a[i] - '0');
    }

    for (int i = b.size() - 1; i >= 0; i--) {
        B.push_back(b[i] - '0');
    }

    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B.size(); j++) {
            C[i + j] += A[i] * B[j];
        }
    }

    for (int i = 0; i < C.size() - 1; i++) {
        if (C[i] >= 10) {
            C[i + 1] += C[i] / 10;
            C[i] = C[i] % 10;
        }
    }

    while (C.size() > 1 && C.back() == 0) {
        C.pop_back();
    }

    return C;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string a, b;
        cin >> a >> b;
        auto C = mul(a, b);
        for (int j = C.size() - 1; j >= 0; j--) {
            cout << C[j];
        }

        cout << endl;
    }

    return 0;
}
