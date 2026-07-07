class Solution {
public:
    int atmost(vector<int> & nums, int k) {
        int left = 0;
        int n = nums.size();
        int cnt = 0;
        unordered_map<int, int> freq;

        for(int right = 0; right < n; right++) {
            freq[nums[right]]++;

            while(freq.size() > k){
                freq[nums[left]]--;

                if(freq[nums[left]] == 0) freq.erase(nums[left]);

                left++;
            }

            cnt += (right - left + 1);
        }

        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k - 1);
        
    }
};