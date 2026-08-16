class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int, int> mpp;

        int actual_sum = accumulate(nums.begin(), nums.end(), 0);

        int sum = ((n * (n + 1)) / 2);

        int diff = sum - actual_sum;

        for(int i = 0; i < n; i++) {
            if(mpp.find(nums[i]) == mpp.end()){
                mpp[nums[i]]++;
            }
            else{
                return {nums[i], nums[i] + diff};
            }
        }

        return {-1};
    }
};