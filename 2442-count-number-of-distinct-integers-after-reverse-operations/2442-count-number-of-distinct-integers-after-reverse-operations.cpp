class Solution {
public:

    int reversenum(int num) {

        int rev = 0;

        while(num > 0){

            rev = rev * 10 + num % 10;
            num /= 10;
        }

        return rev;
    }
    int countDistinctIntegers(vector<int>& nums) {

        unordered_set<int> distinct;

        for(int num : nums){

            distinct.insert(num);
            distinct.insert(reversenum(num));
        }

        return distinct.size();
        
    }
};