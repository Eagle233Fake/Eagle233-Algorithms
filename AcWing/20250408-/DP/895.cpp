#include <bits/stdc++.h>

using ll = long long;

using namespace std;

const int N = 1010;

ll a[N];
ll dp[N];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    ll mmax = INT_MIN;
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }  
        }
        mmax = max(dp[i], mmax);
    }

    cout << mmax << endl;
    return 0;
}
