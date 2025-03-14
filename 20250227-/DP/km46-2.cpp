#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int m, n;
    cin >> m >> n;
    vector<int> dp(n + 1, 0);

    int weight[m + 1] = {0};
    for (int i = 1; i <= m; i++) {
        cin >> weight[i];
    }

    int value[m + 1] = {0};
    for (int i = 1; i <= m; i++) {
        cin >> value[i];
    }

    for (int i = 1; i <= m; i++) {
        for (int j = n; j >= weight[i]; j--) {
            dp[j] = max(dp[j], value[i] + dp[j - weight[i]]); // 不用考虑在weight之前的情况，因为已经在上一次的基础上被初始化了
        }
    }

    cout << dp[n];
}