class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size();

        int numsum = accumulate(nums.begin(), nums.end(), 0);

        int act_sum = (n * (n + 1)) / 2;

        return act_sum - numsum;

    }
};