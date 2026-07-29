class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int m = image.size();
        int n = image[0].size();

        queue<pair<int, int>> q;

        q.push({sr, sc});
        int original = image[sr][sc];

        if(original == color) return image;

         image[sr][sc] = color;

        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();


            for(int i = 0; i < 4; i++) {
                int trow = row + drow[i];
                int tcol = col + dcol[i];

                if(trow >= 0 && trow < m && tcol >= 0 && tcol < n && image[trow][tcol] == original) {
                    q.push({trow, tcol});
                    image[trow][tcol] = color;
                }
            }
        }

        return image;

        
    }
};