class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        
        int n = nums.size();

        vector<int> dp(n, 1);

        vector<int> parent(n);

        int maxseq = 1;

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int lastindex = 0;
        int maxlen = 1;

        for(int i = 1; i < n; i++) {

            for(int j = 0; j < i; j++) {

                if(nums[i] % nums[j] == 0) {

                    if(dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }

                }
            }

            if(dp[i] > maxseq) {
                maxseq = dp[i];
                lastindex = i;
            }
        }

        vector<int> res;

        while(parent[lastindex] != lastindex) {
            res.push_back(nums[lastindex]);
            lastindex = parent[lastindex];
        }

        res.push_back(nums[lastindex]);

        reverse(res.begin(), res.end());

        return res;
    }
};