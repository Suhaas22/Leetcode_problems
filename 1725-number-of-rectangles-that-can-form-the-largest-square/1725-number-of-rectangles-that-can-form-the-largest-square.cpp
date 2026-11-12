class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        
        int maxlen = 0;
        int count = 0;

        for(auto rec : rectangles){

            int minimum = min(rec[0], rec[1]);

            if(minimum > maxlen){
                maxlen = minimum;
                count = 1;
            }
            else if(maxlen == minimum){
                count++;
            }
        }

        return count;


    }
};