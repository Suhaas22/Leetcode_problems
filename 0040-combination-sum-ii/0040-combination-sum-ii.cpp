class Solution {
public:
    void combsum(vector<int> & candidates, int target, int ind, int & sum, vector<int> & cont, vector<vector<int>> & res) {

        if(sum == target) {
            res.push_back(cont);
            return;
        }

        if(sum > target || ind == candidates.size()) {
            return;
        }

        sum += candidates[ind];
        cont.push_back(candidates[ind]);

        combsum(candidates, target, ind + 1, sum, cont, res);

        sum -= candidates[ind];
        cont.pop_back();

         // Don't take current element
        // Skip duplicate values

        int next = ind + 1;

        while(next < candidates.size() && candidates[next] == candidates[ind]) {
            next++;
        }

        combsum(candidates, target, next, sum, cont, res);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        int sum = 0;
        vector<int> cont;
        vector<vector<int>> res;

        combsum(candidates, target, 0, sum, cont, res);

        return res;
    }
};