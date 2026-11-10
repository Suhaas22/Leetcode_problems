class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {

        vector<int> dp(n + 1, 1e9);

        dp[0] = 0;

        for(int i = 1; i < n + 1; i++){

            dp[i] = costs[i - 1] + min({
           (i >= 1? dp[i - 1] + 1 : (int) 1e9),
           (i >= 2? dp[i - 2] + 4 : (int) 1e9),
           (i >= 3? dp[i - 3] + 9 : (int) 1e9)
           });
        }

        return dp[n];
    }
};