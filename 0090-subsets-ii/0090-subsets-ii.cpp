class Solution {
public:
    void subsets(vector<int> & nums, int ind, vector<vector<int>> &res, vector<int> &curr) {

        if(ind == nums.size()) {
            res.push_back(curr);
            return;
        }

        curr.push_back(nums[ind]);

        subsets(nums, ind + 1, res, curr);

        curr.pop_back();

        int next = ind + 1;

        while(next < nums.size() && nums[next] == nums[ind]){
            next++;
        }

        subsets(nums, next, res, curr);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        vector<int> curr;

        subsets(nums, 0, res, curr);

        return res;
    }
};