class Solution {
    private:
    void dfs(int node, vector<int> & vis, vector<vector<int>> & adj){
        vis[node] = 1;

        for(int el : adj[node]){
            if(!vis[el]){
                dfs(el, vis, adj);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int N = isConnected.size();
        vector<vector<int>> adjls(N);

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {

                if(isConnected[i][j] == 1){
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }

            }
        }

        vector<int> vis(N, 0);
        int cnt = 0;

        for(int i = 0; i < N ; i++) {
            if(!vis[i]){
                cnt++;
                dfs(i, vis, adjls);
            }
        }

        return cnt;


    }
};