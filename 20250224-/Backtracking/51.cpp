class Solution {
    public:
        vector<vector<string>> result;
    
        bool isValid(int n, int row, int col, vector<string> &chessBoard) {
            for (int i = 0; i < n; i++) {
                if (chessBoard[i][col] == 'Q') {
                    return false;
                }
            }
    
            for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
                if (chessBoard[i][j] == 'Q') {
                    return false;
                }
            }
    
            for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
                if (chessBoard[i][j] == 'Q') {
                    return false;
                }
            }
            
            return true;
        }
    
        void backtracking(int row, int n, vector<string> &chessBoard) {
            if (row == n) {
                result.push_back(chessBoard);
                return;
            }
    
            for (int i = 0; i < n; i++) {
                if (isValid(n, row, i, chessBoard)) {
                    chessBoard[row][i] = 'Q';
                    backtracking(row + 1, n, chessBoard);
                    chessBoard[row][i] = '.';
                }
            }
        }
    
        vector<vector<string>> solveNQueens(int n) {
            vector<string> chessBoard(n, string(n, '.'));
            backtracking(0, n, chessBoard);
            return result;
        }
    };