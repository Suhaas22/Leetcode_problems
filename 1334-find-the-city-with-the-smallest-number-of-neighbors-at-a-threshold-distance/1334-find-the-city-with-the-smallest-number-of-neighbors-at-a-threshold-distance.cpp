class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<int>> cost(n, vector<int>(n, 1e9));

        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            cost[u][v] = wt;
            cost[v][u] = wt;
        }

        for(int i = 0; i < n; i++) {
            cost[i][i] = 0;
        }

        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
                }
            }
        }

                int minCount = INT_MAX;
        int ans = -1;

        for(int i = 0; i < n; i++) {

            int cnt = 0;

            for(int j = 0; j < n; j++) {
                if(cost[i][j] <= distanceThreshold) {
                    cnt++;
                }
            }

            // <= handles the tie:
            // choose the city with the larger index
            if(cnt <= minCount) {
                minCount = cnt;
                ans = i;
            }
        }

        return ans;
    }
};