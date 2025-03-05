class Solution {
    public:
        int integerBreak(int n) {
            int dp[58] = {0};
            dp[0] = 0;
            dp[1] = 1;
            dp[2] = 2;
            dp[3] = 3;
    
            if (n == 2) {
                return 1;
            } else if (n == 3) {
                return 2;
            } else {
                for (int i = 4; i <= n; i++) {
                    for (int j = 0; j <= i / 2; j++) {
                        dp[i] = max(dp[j] * dp[i - j], dp[i]);
                    }
                }
            }
    
            return dp[n];
        }
    };