class Solution {
public:
    int sumofdigits(int num) {
        int sum = 0;

        while(num > 0) {
            int dig = num % 10;
            sum += dig;
            num = num / 10;
        }

        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        
        int res = -1;

        for(int i = 0; i < nums.size(); i++) {
            if(sumofdigits(nums[i]) == i) {
                res = i;
                break;
            }
        }

        return res;
    }
};