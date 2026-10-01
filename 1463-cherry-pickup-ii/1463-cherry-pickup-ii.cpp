class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, 0)));

        for(int c1 = 0; c1 < n; c1++) {
            for(int c2 = 0; c2 < n; c2++) {

                if(c1 == c2) {
                    dp[m - 1][c1][c2] = grid[m - 1][c1];
                }
                else{
                    dp[m - 1][c1][c2] = grid[m - 1][c1] + grid[m - 1][c2];
                }
            }
        }   


        for(int r = m - 2; r >= 0; r--) {
            for(int c1 = 0; c1 < n; c1++) {
                for(int c2 = 0; c2 < n; c2++) {

                    int cherries = grid[r][c1];

                    if(c1 != c2){
                        cherries += grid[r][c2];
                    }

                    int best = INT_MIN;

                    for(int d1 = -1; d1 < 2; d1++) {
                        for(int d2 = -1; d2 < 2; d2++) {

                            int nc1 = c1 + d1;
                            int nc2 = c2 + d2;

                            if(nc1 >= 0 && nc1 < n && nc2 >= 0 && nc2 < n) {
                                best = max(best, dp[r + 1][nc1][nc2]);
                            }
                        }
                    }

                    dp[r][c1][c2] = best + cherries;
                }
            }
        }

        return dp[0][0][n - 1];
    }
};