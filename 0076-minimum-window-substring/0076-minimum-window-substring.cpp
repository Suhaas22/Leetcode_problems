class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char, int> need;
        unordered_map<char, int> window;

        for(auto c : t) need[c]++;

        int required = need.size();
        int formed = 0;
        int left = 0;
        int start = 0;
        int minlen = INT_MAX;

        for(int right = 0; right < s.size(); right++) {

            window[s[right]]++;

            if(need.count(s[right]) && window[s[right]] == need[s[right]]){
                formed++;
            }

            while(formed == required) {
                if((right - left + 1) < minlen) {
                    minlen = right - left + 1;
                    start = left;
                }

                window[s[left]]--;

                if(need.count(s[left]) && window[s[left]] < need[s[left]]){
                    formed--;
                }

                left++;
            }
        }

        if(minlen == INT_MAX) return "";

        return s.substr(start, minlen);
    }
};