class DSU {
    public:
    vector<int> size, parent;

    DSU(int n) {
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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        int rows = 0;
        int cols = 0;

        for(auto &it : stones) {
            rows = max(rows, it[0]);
            cols = max(cols, it[1]);
        }

        DSU dsu(rows + cols + 2);

        unordered_map<int, int> stonemap;

        for(auto it : stones) {
            int noderow = it[0];
            int nodecol = rows + it[1] + 1;

            dsu.unite(noderow, nodecol);

            stonemap[noderow] = 1;
            stonemap[nodecol] = 1;
        }

        int components = 0;

        for(auto it : stonemap) {
            if(dsu.findUpar(it.first) == it.first){
                components++;
            }
        }

        return n - components;
    }
};