class Solution {
public:
    bool check(string &shorter, string &longer) {

        if(shorter.size() != longer.size() - 1) return false;

        int i = 0;
        int j = 0;

        while(i < shorter.size() && j < longer.size()) {

            if(shorter[i] == longer[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }

        return i == shorter.size();
    }

    int longestStrChain(vector<string>& words) {

        sort(words.begin(), words.end(), 
        [](string &a, string &b){
            return a.size() < b.size();
            });

        int n = words.size();

        int maxseq = 1;

        vector<int> dp(n, 1);

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < i; j++) {

                if(check(words[j], words[i])){

                    if(dp[j] + 1 > dp[i]){

                        dp[i] = dp[j] + 1;
                    }

                }
            }

            if(dp[i] > maxseq) {
                maxseq = dp[i];
            }
        }

        return maxseq;
    }
};