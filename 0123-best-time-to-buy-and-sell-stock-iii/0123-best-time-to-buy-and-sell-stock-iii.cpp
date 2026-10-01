class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // int n = prices.size();

        // vector<vector<int>> dp(n, vector<int> (5, 0));

        // dp[0][0] = 0;
        // dp[0][1] = -prices[0];
        // dp[0][2] = 0;
        // dp[0][3] = -prices[0];
        // dp[0][4] = 0;

        // for(int i = 1; i < n; i++) {

        //     dp[i][0] = dp[i - 1][0];

        //     dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);

        //     dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);

        //     dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);

        //     dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
        // }

        // return dp[n - 1][4];



        // if asked with O(0) space

      
        int buy1 = INT_MIN;
        int sell1 = 0;
        int buy2 = INT_MIN;
        int sell2 = 0;

        for(int price : prices) {
        buy1 = max(buy1, -price);
        sell1 = max(sell1, buy1 + price);
        buy2 = max(buy2, sell1 - price);
        sell2 = max(sell2, buy2 + price);
        }

        return sell2;
        
      
        
    }
};