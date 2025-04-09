class Solution {
    public:
        bool isValid(int row, int col, vector<vector<char>>& board, char k) {
            for (int i = 0; i < 9; i++) {
                if (board[i][col] == k) {
                    return false;
                }
            }
    
            for (int j = 0; j < 9; j++) {
                if (board[row][j] == k) {
                    return false;
                }
            }
    
            int r = row / 3 * 3;
            int c = col / 3 * 3;
    
            for (int i = r; i < r + 3; i++) {
                for (int j = c; j < c + 3; j++) {
                    if (board[i][j] == k) {
                        return false;
                    }
                }
            }
    
            return true;
        }
    
        bool backtracking(vector<vector<char>>& board) {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (board[i][j] == '.') {
                        for (char k = '1'; k <= '9'; k++) {
                            if (isValid(i, j, board, k)) {
                                board[i][j] = k;
                                if (backtracking(board)) {
                                    return true;
                                }
                                board[i][j] = '.';
                            }
                        }
                        return false;
                    }
                }
            }
            return true;
        }
    
        void solveSudoku(vector<vector<char>>& board) {
            backtracking(board);
        }
    };