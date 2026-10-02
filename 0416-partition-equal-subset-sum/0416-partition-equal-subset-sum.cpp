class Solution {
public:
    bool solve(int ind, int curr_sum, vector<vector<int>> &dp, vector<int> &nums, int target) {

        if(curr_sum == target) return true;

        if(ind == nums.size()) return false;

        if(dp[ind][curr_sum] != -1) return dp[ind][curr_sum];

        bool take = false;

        if(curr_sum + nums[ind] <= target) {
            take = solve(ind + 1, curr_sum + nums[ind], dp, nums, target);
        }

        bool leave = solve(ind + 1, curr_sum, dp, nums, target);

        return dp[ind][curr_sum] = take || leave;
    }
    bool canPartition(vector<int>& nums) {

        int n = nums.size();

        int totalsum = accumulate(nums.begin(), nums.end(), 0);

        if(totalsum & 1) return false;

        int target = totalsum / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return solve(0, 0, dp, nums, target);
    }
};