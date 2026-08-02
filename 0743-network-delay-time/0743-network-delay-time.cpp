class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int, int>>> adj(n + 1);

        for(int i = 0; i < times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int weight = times[i][2];

            adj[u].push_back({weight, v});
        }

        set<pair<int, int>> st;
        st.insert({0, k});

        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;

        while(!st.empty()) {
            auto it = *(st.begin());
            int dweight = it.first;
            int node = it.second;
            st.erase(it);

            for(auto &adj : adj[node]) {
                int edgeweight = adj.first;
                int adjnode = adj.second;

                if(edgeweight + dweight < dist[adjnode]){

                    if(dist[adjnode] != 1e9){
                        st.erase({dist[adjnode], adjnode});
                    }

                    dist[adjnode] = dweight + edgeweight;

                    st.insert({dweight + edgeweight, adjnode});
                }
            }
        }

        int ans = 0;

    for(int i = 1; i <= n; i++) {

        if(dist[i] == 1e9)
            return -1;

        ans = max(ans, dist[i]);
    }

    return ans;
    }
};