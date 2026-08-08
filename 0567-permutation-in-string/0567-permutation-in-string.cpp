class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.length() > s2.length()) {
            return false;
        }

        vector<int> windowfreq(26, 0);
        vector<int> s1freq(26, 0);

        for(char c : s1) {
            s1freq[c - 'a']++;
        }

        int windowsize = s1.length();

        for(int i = 0; i < windowsize; i++) {
            windowfreq[s2[i] - 'a']++;
        }

        if(windowfreq == s1freq) return true;

        for(int right = windowsize; right < s2.length(); right++) {

            windowfreq[s2[right] - 'a']++;

            int left = right - windowsize;

            windowfreq[s2[left] - 'a']--;

            if(s1freq == windowfreq) return true;
        }

        return false;
    }
};