#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int C, N;
    cin >> C >> N;
    
    vector<int> weight(N);
    vector<int> value(N);
    vector<int> nums(N);

    for (int i = 0; i < N; i++) {
        cin >> weight[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> value[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }


    vector<int> dp(C + 1, 0);

    for (int i = 0; i < N; i++) {
        for (int j = C; j >= weight[i]; j--) {
            for (int k = 1; k <= nums[i] && (j - k * weight[i]) >= 0; k++) {
                dp[j] = max(dp[j], dp[j - k * weight[i]] + k * value[i]);
            }
        }
    }

    cout << dp[C] << endl;
}