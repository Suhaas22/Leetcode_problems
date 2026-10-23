class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        unordered_map<int, int> mpp;

        mpp[0] = -1;

        int maxcnt = 0;
        int sum = 0;

        for(int i = 0; i < nums.size(); i++){

            int add = nums[i] == 0 ? -1 : nums[i];
            sum += add;

            if(mpp.count(sum)){
                maxcnt = max(maxcnt, i - mpp[sum]);
            }
            else{
                mpp[sum] = i;
            }

        }

        return maxcnt;
    }
};