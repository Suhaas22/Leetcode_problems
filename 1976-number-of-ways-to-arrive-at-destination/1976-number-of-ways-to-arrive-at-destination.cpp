class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        int MOD = 1e9 + 7;

        int m = roads.size();

        vector<vector<pair<int, int>>> adj(n);

        for(auto &road : roads) {
            int u = road[0];
            int v = road[1];
            int t = road[2];

            adj[u].push_back({t, v});
            adj[v].push_back({t, u});
        }

        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;

        vector<int> ways(n, 0);
        ways[0] = 1;

        priority_queue<
    pair<long long, int>,
    vector<pair<long long, int>>,
    greater<pair<long long, int>>
> pq;
        pq.push({0, 0});

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();



            long long disttillu = it.first;
            int u = it.second;

                        if(disttillu > dist[u])
    continue;



            for(auto &adjacent : adj[u]){
                int edgeweight = adjacent.first;
                int adjnode = adjacent.second;

                if(disttillu + edgeweight < dist[adjnode]){
                    dist[adjnode] = disttillu + edgeweight;
                    ways[adjnode] = ways[u];
                    pq.push({dist[adjnode], adjnode});
                }
                else if(disttillu + edgeweight == dist[adjnode]){
                    ways[adjnode] = (ways[adjnode] + ways[u]) % MOD;
                }
            }
        }

        return ways[n - 1];

    }
};