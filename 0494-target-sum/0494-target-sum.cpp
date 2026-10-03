class Solution {
public:
    int solve(int ind, int curr_sum, vector<int>&nums, int target, int sum, vector<vector<int>> &dp) {

        if(ind == nums.size()){
            return curr_sum == target;
        }

        if(dp[ind][curr_sum + sum] != -1) return dp[ind][curr_sum + sum];

        int add = solve(ind + 1, curr_sum + nums[ind], nums, target, sum, dp);

        int leave = solve(ind + 1, curr_sum - nums[ind], nums, target, sum, dp);

        return dp[ind][curr_sum + sum] = add + leave;
    }
    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> dp(n, vector<int>(2 * sum + 1, -1));

        return solve(0, 0, nums, target, sum, dp);

    }
};