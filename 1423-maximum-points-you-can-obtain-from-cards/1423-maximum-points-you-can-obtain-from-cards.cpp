class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        if(k == n){
            return accumulate(cardPoints.begin(), cardPoints.end(), 0);
        }

        int totalsum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int windsize = n - k;
        int windsum = 0;

        for(int i = 0; i < windsize; i++) {
            windsum += cardPoints[i];
        }

        int minsum = windsum;

        for(int right = windsize; right < n; right++){
            windsum += cardPoints[right];
            windsum -= cardPoints[right - windsize];

            minsum = min(minsum, windsum);
        }

        return totalsum - minsum;


        
    }
};