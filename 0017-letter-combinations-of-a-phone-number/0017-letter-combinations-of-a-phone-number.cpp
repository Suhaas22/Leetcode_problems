class Solution {
public:
    void solve(string digits, int ind, unordered_map<int, string> &mpp, string &curr, vector<string> &res) {
        if(ind == digits.size()) {
            res.push_back(curr);
            return;
        }

        string letters = mpp[digits[ind] - '0'];

        for(char ch : letters) {

            curr.push_back(ch);

            solve(digits, ind + 1, mpp, curr, res);

            curr.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {

        unordered_map<int, string> mpp(10);

        mpp[2] = "abc";
        mpp[3] = "def";
        mpp[4] = "ghi";
        mpp[5] = "jkl";
        mpp[6] = "mno";
        mpp[7] = "pqrs";
        mpp[8] = "tuv";
        mpp[9] = "wxyz";

        string curr;
        vector<string> res;
        int ind = 0;
        
        solve(digits, ind, mpp, curr, res);

        return res;
    }
};