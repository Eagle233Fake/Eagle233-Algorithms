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
    
    vector<vector<int>> dp(n);
    dp[0] = {0};
    dp[1] = {1};

    for (int i = 2; i < n; i++) {
        for (int j = i - 1; j >= i - k && j >= 0; j--) {
            dp[i] = add(dp[i], dp[j]);
        }
    }

    for (int i = dp[n - 1].size() - 1; i >= 0; i--) {
        cout << dp[n - 1][i];
    }

    cout << endl;
    return 0;
}
