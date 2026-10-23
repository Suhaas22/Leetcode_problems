class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> freq;

        for(string str : strs){

            string key = str;

            sort(key.begin(), key.end());

            freq[key].push_back(str);
        }

        vector<vector<string>> ans;

        for(auto var : freq){
            

            ans.push_back(var.second);
        }

        return ans;
    }
};