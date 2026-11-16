class Solution {
public:
    int stringsum(string str){
        int sum = 0;

        for(auto ch : str){
            sum += ch - '0';
        }

        return sum;
    }

    string digitSum(string s, int k) {

        while(s.size() > k){

            string ans = "";

            for(int i = 0; i < s.size(); i += k){

                string sub = s.substr(i, k);
                int sum = stringsum(sub);
                ans += to_string(sum);

            }

            s = ans;
        }
        
        return s;
    }
};