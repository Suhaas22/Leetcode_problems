class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;

        int n = nums.size();

        for(int num : nums){
            mpp[num]++;
        }

        vector<vector<int>> bucket(n + 1);

        for(auto &p : mpp){
            bucket[p.second].push_back(p.first);
        }

        vector<int> ans;

        for(int i = bucket.size() - 1; i >= 0 && ans.size() < k; i--) {

                for(int num : bucket[i]){
                    ans.push_back(num);

                    if(ans.size() == k){
                        break;
                    }
                }
            
        }

        return ans;
    }
};