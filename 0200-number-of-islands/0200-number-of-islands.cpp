class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        int islands = 0;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j ++) {

                if(grid[i][j] == '1' && !vis[i][j]) {

                    islands++;

                    vis[i][j] = 1;

                    int row = i;
                    int col = j;
                    q.push({row, col});

                    while(!q.empty()) {
                        int r = q.front().first;
                        int c = q.front().second;

                        q.pop();

                        for(int i = 0; i < 4; i++) {

                            int nrow = r + drow[i];
                            int ncol = c + dcol[i];

                            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                                q.push({nrow, ncol});
                                vis[nrow][ncol] = 1;
                            }
                        }
                    }

                }
            }
        }

        return islands;


    }
};