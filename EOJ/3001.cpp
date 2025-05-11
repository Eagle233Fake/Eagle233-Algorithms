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

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            C[i + j] += A[i] * B[j];
        }
    }

    for (int i = 0; i < C.size() - 1; i++) {
        if (C[i] >= 10) {
            C[i + 1] += C[i] / 10;
            C[i] %= 10;
        }
    }

    while (C.size() > 1 && C.back() == 0) {
        C.pop_back();
    }

    return C;
}

string v2s(vector<int> &C) {
    string c;
    for (int i = C.size() - 1; i >= 0; i--) {
        c.push_back(C[i] + '0');
    }

    return c;
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
    auto C = mul(a, a);
    auto c = v2s(C);
    for (int i = 2; i < n; i++) {
        C = mul(c, a);
        c = v2s(C);
    }

    cout << c;
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
