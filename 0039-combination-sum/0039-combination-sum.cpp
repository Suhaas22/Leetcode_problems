class Solution {
public:
    void combsum(vector<int> & candidates, int target, int ind, int & sum, vector<int> & cont, vector<vector<int>> & res) {

        if(sum == target) {
            res.push_back(cont);
            return;
        }

        if(ind == candidates.size() || sum > target) {
            return;
        }

        cont.push_back(candidates[ind]);
        sum += candidates[ind];

        combsum(candidates, target, ind, sum, cont, res);

        cont.pop_back();
        sum -= candidates[ind];

        combsum(candidates, target, ind + 1, sum, cont, res);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        int sum = 0;
        vector<int> cont;
        vector<vector<int>> res;

        combsum(candidates, target, 0, sum, cont, res);   

        return res;
    }
};