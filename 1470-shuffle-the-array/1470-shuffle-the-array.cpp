class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {

        vector<int> res(2*n);

        int left = 0;
        int right = n;

        for(int i = 0; i < 2 * n; i += 2) {
            res[i] = nums[left];
            res[i + 1] = nums[right];

            left++;
            right++;
        }

        return res;
    }
};