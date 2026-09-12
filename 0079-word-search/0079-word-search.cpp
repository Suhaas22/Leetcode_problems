class Solution {
public:
    bool wordsearch(vector<vector<char>> &board, string word, int row, int col, int ind, vector<int> &drows, vector<int> &dcols) {

        if(ind == word.size()) return true;

        int rows = board.size();
        int cols = board[0].size();

        for(int i = 0; i < 4; i++) {
            int nrow = row + drows[i];
            int ncol = col + dcols[i];

            if(nrow >= 0 && nrow < rows && ncol >= 0 && ncol < cols && board[nrow][ncol] == word[ind]) {

                char temp = board[nrow][ncol];
                board[nrow][ncol] = '#';

                if(wordsearch(board, word, nrow, ncol, ind + 1, drows, dcols)) return true;

                board[nrow][ncol] = temp;

            }
        }

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        vector<int> drows = {1, 0, -1, 0};
        vector<int> dcols = {0, 1, 0, -1};

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {

                if(board[i][j] == word[0]) {

                    char temp = board[i][j];
                    board[i][j] = '#';

                    if(wordsearch(board, word, i, j, 1, drows, dcols)) {
                        return true;
                    }

                    board[i][j] = temp;
                }
            }
        }

        return false;
        
    }
};