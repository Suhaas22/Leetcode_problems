class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0;
        int ans = 0;
        unordered_map<char, int> lastindex;

        for(int right = 0; right < n; right++){
            if(lastindex.count(s[right])){
                left = max(left, lastindex[s[right]] + 1);
            }

            lastindex[s[right]] = right;
            ans = max(ans, right - left + 1);
        }

        return ans;
        
    }
};