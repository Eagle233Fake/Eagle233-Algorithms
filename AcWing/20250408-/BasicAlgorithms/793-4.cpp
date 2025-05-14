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
            C[i + 1] += (C[i] / 10);
            C[i] %= 10;
    }

    while (C.size() > 1 && C.back() == 0) {
        C.pop_back();
    }

    return C;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string a;
    string b;
    cin >> a >> b;
    vector<int> A;
    vector<int> B;
    for (int i = a.size() - 1; i >= 0; i--) {
        A.push_back(a[i] - '0');
    }

    for (int i = b.size() - 1; i >= 0; i--) {
        B.push_back(b[i] - '0');
    }

    auto C = mul(A, B);

    for (int i = C.size() - 1; i >= 0; i--) {
        cout << C[i];
    }

    cout << endl;

    return 0;
}
