class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        if(p.length() > s.length()) return {};

        vector<int> windowfreq(26, 0);
        vector<int> pfreq(26, 0);

        for(char ch : p) {
            pfreq[ch - 'a']++;
        }   

        int windowsize = p.length();

        vector<int> ans;

        for(int i = 0; i < windowsize; i++) {
            windowfreq[s[i] - 'a']++;
        }

        int left;
        int right;

        for(right = windowsize; right < s.length(); right++) {

            left = right - windowsize;

            if(pfreq == windowfreq) {
                ans.push_back(left);
            }

            windowfreq[s[right] - 'a']++;
            windowfreq[s[left] - 'a']--;
        }

        left = right - windowsize;

        if(pfreq == windowfreq) {
            ans.push_back(left);
        }


        return ans;
        
    }
};