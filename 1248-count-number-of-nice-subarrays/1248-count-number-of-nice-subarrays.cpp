class Solution {
public:
    int atmost(vector<int> & nums, int k) {
        if(k < 0) return 0;

        int n = nums.size();
        int left = 0;
        int cnt = 0;
        int oddcount = 0;

        for(int right = 0; right < n; right++) {

            if(nums[right] & 1){
                oddcount++;
            }

            while(oddcount > k){
                if(nums[left] & 1){
                    oddcount--;
                }

                left++;
            }

            cnt += (right - left + 1);
        }

        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k - 1);
    }
};