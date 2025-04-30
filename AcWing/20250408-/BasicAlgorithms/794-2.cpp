#include <bits/stdc++.h>

using namespace std;

void div(vector<int> &A, int B) {
    int t = 0;
}

int main(void) {
    string a;
    int B;
    cin >> a >> B;
    vector<int> A;
    for (int i = a.size() - 1; i >= 0; i--) {
        A.push_back(a[i] - '0');
    }

    auto C = div(A, B);
    for (int i = C.size() - 1; i >= 0; i--) {
        cout << C[i];
    }

    cout << endl;
}