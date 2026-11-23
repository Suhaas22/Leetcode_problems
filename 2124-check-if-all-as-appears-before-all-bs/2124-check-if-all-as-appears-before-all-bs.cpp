class Solution {
public:
    bool checkString(string s) {
        
        int ind = s.find('b');

        if(ind == string::npos) return true;

        return s.find('a', ind) == string::npos;
    }
};