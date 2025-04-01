class Solution {
    public:
        vector<vector<int>> generateMatrix(int n) {
            int startX = 0;
            int startY = 0;
            int offset = 1;
            int count = 1;
            int loop = n / 2;
            int i = startY;
            int j = startX;
            vector<vector<int>> v(n, vector<int>(n, 0));
            while (loop--) {
                j = startX;
                i = startY;
                for (j = startX; j < n - offset; j++) {
                    v[i][j] = count++;
                }
                for (i = startY; i < n - offset; i++) {
                    v[i][j] = count++;
                }
                for (; j > startX; j--) {
                    v[i][j] = count++;
                }
                for (; i > startY; i--) {
                    v[i][j] = count++;
                }
                startX++;
                startY++;
                offset++;
            }
    
            if (n % 2 == 1) {
                v[n / 2][n / 2] = count;
            }
    
            return v;
        }
    };