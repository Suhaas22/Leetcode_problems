class Solution {
public:

    void solve(int col, vector<int> & row, vector<int> & upperdiag, vector<int> & lowerdiag, vector<vector<string>> & ans, vector<string> &board) {

        int n = board.size();

        if(col == n) {
            ans.push_back(board);
            return;
        }

        for(int i = 0; i < n; i++) {

            if(row[i] || lowerdiag[i + col] || upperdiag[n - 1 + col - i]) {
                continue;
            }

            row[i] = 1;
            lowerdiag[i + col] = 1;
            upperdiag[n - 1 + col - i] = 1;

            board[i][col] = 'Q';

            solve(col + 1, row, upperdiag, lowerdiag, ans, board);

            row[i] = 0;
            lowerdiag[i + col] = 0;
            upperdiag[n - 1 + col - i] = 0;

            board[i][col] = '.';
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        vector<string> board(n);

        string s(n, '.');

        for(int i = 0; i < n; i++) {
            board[i] = s;
        }

        vector<int> row(n, 0);
        vector<int> lowerdiag(2 * n - 1, 0);
        vector<int> upperdiag(2 * n - 1, 0);

        solve(0, row, upperdiag, lowerdiag, ans, board);

        return ans;

        
    }
};