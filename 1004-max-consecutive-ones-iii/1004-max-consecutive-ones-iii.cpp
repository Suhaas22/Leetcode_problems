class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int len = 0;
        int countzeros = 0;

        for(int right = 0; right < n; right++) {
            //counting zeros until k
            if(nums[right] == 0) {
                countzeros++;
            }

            //removing the excessive zeros from the window
            while(countzeros > k) {
                if(nums[left] == 0) {
                    countzeros--;
                }

                left++;
            }

            //valid window
            len = max(len, right - left + 1);
        }
        
        return len;
    }
};