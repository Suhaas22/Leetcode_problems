class Solution {
public:
    int passwordStrength(string password) {

        unordered_set<int> seen;

        int score = 0;

        string expressions = "!@#$";

        for(char ch : password) {
            if(seen.count(ch) == 0) {

                if(ch >= 'a' && ch <= 'z') score += 1;
                else if(ch >= 'A' && ch <= 'Z') score += 2;
                else if(ch >= '0' && ch <= '9') score += 3;
                else if(expressions.find(ch) != string::npos) score += 5;
                
            }

            seen.insert(ch);
        }

        return score;
    }
};