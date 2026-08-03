class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for(int i = 0; i < flights.size(); i++) {

            int from = flights[i][0];
            int to = flights[i][1];
            int price = flights[i][2];

            adj[from].push_back({price, to});
        }

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}}); // {stops, {node, weight}}

        while(!q.empty()) {
            int stops = q.front().first;
            int node = q.front().second.first;
            int pricetillnode = q.front().second.second;

            q.pop();

            if(stops > k) continue;

            for(auto &it : adj[node]) {
                int price = it.first;
                int adjnode = it.second;

                if(pricetillnode + price < dist[adjnode] && stops <= k) {
                    dist[adjnode] = pricetillnode + price;
                    q.push({stops + 1, {adjnode, pricetillnode + price}});
                }
            }
            

    }

    if(dist[dst] == INT_MAX){
        return -1;
    }

    return dist[dst];
    }
};