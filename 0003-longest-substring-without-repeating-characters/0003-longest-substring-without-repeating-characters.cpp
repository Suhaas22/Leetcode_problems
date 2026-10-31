class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.size();
        int left = 0;
        unordered_map<char, int> freq;

        int max_len = 0;

        for(int right = 0; right < n; right++){

            freq[s[right]]++;

            while(freq[s[right]] > 1){
                freq[s[left]]--;
                left++;
            }

            max_len = max(max_len, right - left + 1);

        }

        return max_len;
    }
};