class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n + 2, INT_MAX));

        for(int i = 1; i < n + 1; i++) {
            dp[0][i] = matrix[0][i - 1];
        }

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n + 1; j++) {

                int sum = matrix[i][j - 1] + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1]});

                dp[i][j] = sum;
                
            }
        }

        int res = INT_MAX;

        for(int i = 1; i < n + 1; i++) {
            
            res = min(res, dp[m - 1][i]);
        }

        return res;
        
    }
};