class Solution {
public:
    void combsum(int k, int n, int ind, vector<int> &nums, int &sum, vector<int> &curr, int &cnt, vector<vector<int>> &res) {

        if(cnt == k && sum == n) {
            res.push_back(curr);
            return;
        }

        if(ind == nums.size()) return;

        cnt++;
        sum += nums[ind];
        curr.push_back(nums[ind]);

        combsum(k, n, ind + 1, nums, sum, curr, cnt, res);

        cnt--;
        sum -= nums[ind];
        curr.pop_back();

        combsum(k, n, ind + 1, nums, sum, curr, cnt, res);
    }  
    vector<vector<int>> combinationSum3(int k, int n) {
        int cnt = 0;
        vector<int> curr;
        vector<vector<int>> res;
        int sum = 0;
        int ind = 0;

        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};

        combsum(k, n, ind, nums, sum, curr, cnt, res);

        return res;
 
    }
};