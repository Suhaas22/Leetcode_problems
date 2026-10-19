class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {

        int ind = 0;
        int cnt = 0;

        vector<int> res;

        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] < target){
                ind++;
            }
            else if(nums[i] == target){
                cnt++;
            }
        }   

        for(int i = 0; i < cnt; i++){
            res.push_back(ind + i);
        }

        return res;
    }
};