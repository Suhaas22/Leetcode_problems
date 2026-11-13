class Solution {
public:
    int reversenum(int num){

        int rev = 0;

        while(num > 0){

            rev = rev * 10 + num % 10;
            num /= 10;
        }

        return rev;
    }
    bool sumOfNumberAndReverse(int num) {
        
        for(int i = 0; i <= num; i++){

            if((i + reversenum(i)) == num) return true;
        }

        return false;
    }
};