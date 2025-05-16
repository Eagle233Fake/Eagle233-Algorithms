#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, V;
    cin >> N >> V;

    vector<int> dp(V + 1, 0);

    for (int i = 1; i <= N; i++) {
        int w, v, s;
        cin >> w >> v >> s;
        for (int k = 0; k < s; k++) {
            for (int j = V; j >= w; j--) {
                dp[j] = max(dp[j], dp[j - w] + v);
            }
        }
    }

    cout << dp[V] << endl;
    return 0;
}
