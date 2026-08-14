class DSU {
    public :
    vector<int> parent, size;

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

    void Union(int u, int v) {
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
    private:
    bool isvalid(int row, int col, int n) {
        return row >= 0 && row < n && col >= 0 && col < n;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        DSU dsu(n * n);

        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == 0) continue;

                int drow[] = {1, 0, -1, 0};
                int dcol[] = {0, -1, 0, 1};

                for(int i = 0; i < 4; i++) {
                    int nrow = row + drow[i];
                    int ncol = col + dcol[i];

                    if(isvalid(nrow, ncol, n) && grid[nrow][ncol] == 1) {
                        int nodeno = row * n + col;
                        int adjnodeno = nrow * n + ncol;

                        dsu.Union(nodeno, adjnodeno);
                    }
                }
            }
        }   

        int mx = 0;

        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == 1) continue;

                int drow[] = {-1, 0, 1, 0};
                int dcol[] = {0, 1, 0, -1};

                set<int> st;

                for(int i = 0; i < 4; i++) {
                    int nrow = row + drow[i];
                    int ncol = col + dcol[i];

                    if(isvalid(nrow, ncol, n) && grid[nrow][ncol] == 1) {
                        int ultpar = dsu.findUpar(nrow * n + ncol);
                        st.insert(ultpar);
                    }
                }

                int sum = 0;

                for(int it : st) {
                    sum += dsu.size[it];
                }
                sum++;

                mx = max(mx, sum);
            }
        }

              for(int row = 0; row < n; row++) {

            for(int col = 0; col < n; col++) {

                if(grid[row][col] == 1) {

                    int root =
                        dsu.findUpar(row * n + col);

                    mx = max(mx, dsu.size[root]);
                }
            }
        }

        return mx;
    }
};