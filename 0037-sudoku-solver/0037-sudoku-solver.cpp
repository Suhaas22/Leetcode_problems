class Solution {
public:
    bool row[9][10] = {};
    bool col[9][10] = {};
    bool box[9][10] = {};

    bool solve(vector<vector<char>> &board, int pos) {

        if(pos == 81) return true;

        int r = pos / 9;
        int c = pos % 9;

        if(board[r][c] != '.') {
            return solve(board, pos + 1);
        }

        int b = (r / 3) * 3 + (c / 3);

        for(int d = 1; d <= 9; d++) {

            if(row[r][d] || col[c][d] || box[b][d]) continue;

            board[r][c] = '0' + d;

            row[r][d] = true;
            col[c][d] = true;
            box[b][d] = true;

            if(solve(board, pos + 1)) return true;

            board[r][c] = '.';
            row[r][d] = false;
            col[c][d] = false;
            box[b][d] = false;

        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        
        for(int r = 0; r < 9; r++) {
            for(int c = 0; c < 9; c++) {

                if(board[r][c] == '.') continue;

                int d = board[r][c] - '0';
                int b = (r / 3) * 3 + (c / 3);

                row[r][d] = true;
                col[c][d] = true;
                box[b][d] = true;
            }
        }

        solve(board, 0);

    }
};