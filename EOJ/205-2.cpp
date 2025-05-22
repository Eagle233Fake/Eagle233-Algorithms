#include <bits/stdc++.h>

using namespace std;

vector<int> add(vector<int> &A, vector<int> &B) {
    int t = 0;
    vector<int> C;
    for (int i = 0; i < A.size() || i < B.size(); i++) {
        if (i < A.size()) {
            t += A[i];
        }
        if (i < B.size()) {
            t += B[i];
        }

        C.push_back(t % 10);
        t /= 10;
    }

    if (t) {
        C.push_back(t);
    }

    return C;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int k, n;
    cin >> k >> n;
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    if (n == 2) {
        cout << 1 << endl;
        return 0;
    }


    vector<vector<int>> v(n + 1, {0});

    v[0] = {0};
    v[1] = {0};
    v[2] = {1};

    for (int i = 3; i <= n; i++) {
        for (int j = i - 1; j >= 0 && i - j <= k; j--) {
            v[i] = add(v[i], v[j]);
        }
    }

    for (int i = v[n].size() - 1; i >= 0; i--) {
        cout << v[n][i];
    }

    cout << endl;
    return 0;
}
