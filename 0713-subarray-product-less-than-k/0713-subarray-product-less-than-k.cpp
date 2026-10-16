class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        if(k <= 1) return 0;

        int n = nums.size();

        int left = 0;
        int currprod = 1;
        int cnt = 0;

        for(int right = 0; right < n; right++){

            currprod *= nums[right];

            while(currprod >= k){

                currprod /= nums[left];
                left++;
            }

            cnt += right - left + 1;
        }

        return cnt;
    }
};