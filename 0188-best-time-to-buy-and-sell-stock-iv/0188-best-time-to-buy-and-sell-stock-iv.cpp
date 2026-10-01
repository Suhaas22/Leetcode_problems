class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2 * k + 1, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= 2*k; j++) {

                if(j & 1){
                    dp[i][j] = -prices[i];
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }


        for(int i = 1; i < n; i++) {
            for(int j = 1; j <= 2 * k; j++) {

                if(j & 1) {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + prices[i]);
                }
            }
        }

        return dp[n - 1][2 * k];
    }
};