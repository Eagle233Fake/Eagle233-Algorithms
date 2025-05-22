#include <bits/stdc++.h>

using namespace std;

vector<int> div(vector<int> &A, int B, int &r) {
    vector<int> C;

    int t = 0;

    for (int i = A.size() - 1; i >= 0; i--) {
        t *= 10;
        t += A[i];
        C.push_back(t / B);
        t %= B;
    }

    r = t;

    reverse(C.begin(), C.end());
    while (C.size() > 1 && C.back() == 0) {
        C.pop_back();
    }

    return C;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string a;
    int B;
    cin >> a >> B;

    vector<int> A;
    for (int i = a.size() - 1; i >= 0; i--) {
        A.push_back(a[i] - '0');
    }

    int r;
    auto C = div(A, B, r);

    for (int i = C.size() - 1; i >= 0; i--) {
        cout << C[i];
    }

    cout << endl << r << endl;
    return 0;
}
