class Solution {
public:
    bool isvowel(char s){

        return s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u';
    }
    int maxVowels(string s, int k) {

        int n = s.size();

        int cnt = 0;

        for(int i = 0; i < k; i++){
            if(isvowel(s[i])){
                cnt++;
            }
        }

        int max_cnt = cnt;

        for(int right = k; right < n; right++) {

            if(isvowel(s[right])) cnt++;

            if(isvowel(s[right - k])) cnt--;

            max_cnt = max(max_cnt, cnt);

        }

        return max_cnt;
    }
};