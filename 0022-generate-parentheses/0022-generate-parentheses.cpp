class Solution {
public:
    void generate(int n, int &open_count, int &closed_count, string &s, vector<string> & ans) {

        if(s.size() == 2 * n) {
            ans.push_back(s);
            return;
        }

        if(open_count < n) {
            s.push_back('(');
        open_count++;
        generate(n, open_count, closed_count, s, ans);
        s.pop_back();
        open_count--;
        }

        if(open_count > closed_count) {
            s.push_back(')');
            closed_count++;
            generate(n, open_count, closed_count, s, ans);
            s.pop_back();
            closed_count--;
        }
    }
    vector<string> generateParenthesis(int n) {

        vector<string> ans;
        string s;

        int open_count = 0;
        int closed_count = 0;

        generate(n, open_count, closed_count, s, ans);

        return ans;
    }
};