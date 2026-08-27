class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string, int> freq;

        for(auto word : words) {
            freq[word]++;
        }

        vector<pair<int, string>> ans;

        for(auto &p : freq) {
            ans.push_back({p.second, p.first});
        }

        sort(ans.begin(), ans.end(), [](auto &a, auto &b) {
            
            // a is in form {int, string}

            if(a.first != b.first) {
                return a.first > b.first;
            }

            return a.second < b.second;
        });

        vector<string> res;

        for(int i = 0; i < k; i++) {
            res.push_back(ans[i].second);
        }

        return res;
        
    }
};