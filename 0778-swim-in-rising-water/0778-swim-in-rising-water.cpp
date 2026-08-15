class DSU {
    public:
    vector<int> size, parent;

    DSU (int n) {
        size.resize(n, 1);
        parent.resize(n);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUpar(int node) {
        if(parent[node] == node) return node;

        return parent[node] = findUpar(parent[node]);
    }

    void unite(int u, int v) {
        int pu = findUpar(u);
        int pv = findUpar(v);

        if(pu == pv) return;

        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        DSU dsu(n * n);

        vector<pair<int, int>> cells;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                cells.push_back({grid[i][j], i * n + j});
            }
        }

        sort(cells.begin(), cells.end());

        vector<int> active(n * n, 0);

        int drow[] = {-1, 1, 0, 0};
        int dcol[] = {0, 0, -1, 1};

        for(auto &it : cells) {

            int elevation = it.first;
            int id = it.second;

            int r = id / n;
            int c = id % n;

            active[id] = 1;

            for(int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n) {
                    int neighbour = nrow * n + ncol;

                    if(active[neighbour]) {
                        dsu.unite(id, neighbour);
                    }
                }
            }

            if(dsu.findUpar(0) == dsu.findUpar(n * n - 1)) {
                return elevation;
            }
        }

        return -1;
    }
};