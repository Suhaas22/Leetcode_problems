class Solution {
public:
    int solve(int ind, int accum_value, vector<int> & stones, vector<vector<int>> &dp, int sum){

        if(ind == stones.size()) return abs(2 * accum_value - sum);

        if(dp[ind][accum_value] != -1) return dp[ind][accum_value];

        int take = solve(ind + 1, accum_value + stones[ind], stones, dp, sum);

        int leave = solve(ind + 1, accum_value, stones, dp, sum);

        return dp[ind][accum_value] = min(take, leave);
    }
    int lastStoneWeightII(vector<int>& stones) {

        int n = stones.size();

        int sum = accumulate(stones.begin(), stones.end(), 0);

        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

        return solve(0, 0, stones, dp, sum);
    }
};