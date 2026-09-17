class Solution {
public:
    void solve(int ind, long long prev, long long currvalue, int target, string &num, string &curr, vector<string> &ans ) {

        if(ind == num.size()) {
            if(currvalue == target) {
                ans.push_back(curr);
            }

            return;
        }

        long long currnumber = 0;

        int currlength = curr.size();

        for(int end = ind; end < num.size(); end++) {

            if(end > ind && num[ind] == '0') break;

            string numstr =  num.substr(ind, end - ind + 1);
            currnumber = currnumber * 10 + (num[end] - '0');

            if(ind == 0) {
                curr += numstr;

                solve(end + 1, currnumber, currnumber, target, num, curr, ans);

                curr.resize(currlength);
            }
            else {

                curr += "+" + numstr;

                solve(end + 1, currnumber, currvalue + currnumber, target, num, curr, ans);

                curr.resize(currlength);


                curr += "-" + numstr;

                solve(end + 1, -currnumber, currvalue - currnumber, target, num, curr, ans);

                curr.resize(currlength);

                curr += "*" + numstr;

                solve(end + 1, prev * currnumber, currvalue - prev + prev * currnumber, target, num, curr, ans);

                curr.resize(currlength);
            }
        }
    }
    vector<string> addOperators(string num, int target) {

        vector<string> ans;
        string curr;

        solve(0, 0, 0, target, num, curr, ans);

        return ans;
        
    }
};