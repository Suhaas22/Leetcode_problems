class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, 0));

        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        int maxprof = INT_MIN;

        for(int i = 1; i < n; i++) {

            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);

            dp[i][1] = max(dp[i - 1][0] - prices[i], dp[i - 1][1]);

            maxprof = max({maxprof, dp[i][0], dp[i][1]});
        }

        return (maxprof != INT_MIN) ? maxprof : 0;
    }
};