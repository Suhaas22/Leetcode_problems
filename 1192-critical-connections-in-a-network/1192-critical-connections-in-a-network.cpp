class Solution {
    private:
    int timer = 1;

    void dfs(int node, int parent, vector<int> & vis, vector<int> & low, vector<int> & tin, vector<vector<int>> & adj, vector<vector<int>> & bridges) {

        vis[node] = 1;

        tin[node] = low[node] = timer;

        timer++;

        for(auto it : adj[node]) {
            if(it == parent) continue;

            if(vis[it] == 0) {

                vis[it] = 1;

                dfs(it, node, vis, low, tin, adj, bridges);

                low[node] = min(low[node], low[it]);

                if(tin[node] < low[it]) {
                    bridges.push_back({node, it});
                }
            } 
            else {
                low[node] = min(low[node], low[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>> adj(n);

        for(auto &it : connections) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> tin(n);
        vector<int> vis(n, 0);
        vector<int> low(n);

        vector<vector<int>> bridges;

        dfs(0, -1, vis, low, tin, adj, bridges);

        return bridges;
    }
};