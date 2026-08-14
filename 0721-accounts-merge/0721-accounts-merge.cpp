class DSU {
    public:
    vector<int> parent, size;

    DSU(int n) {
        size.resize(n, 1);
        parent.resize(n);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUpar(int node) {
        if(node == parent[node]) return node;

        return parent[node] = findUpar(parent[node]);
    }

    void Union(int u, int v) {
        int pu = findUpar(u);
        int pv = findUpar(v);

        if(pu == pv) return;

        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int size = accounts.size();
        unordered_map<string, int> mapmailnode;

        DSU dsu(size);

        for(int i = 0; i < size; i++) {
            for(int j = 1; j < accounts[i].size(); j++) {

                if(mapmailnode.find(accounts[i][j]) == mapmailnode.end()) {
                    mapmailnode[accounts[i][j]] = i;
                } else {
                    dsu.Union(i, mapmailnode[accounts[i][j]]);
                }
            }
        }  

        unordered_map<int, vector<string>> mapnodemails;

        for(auto &it : mapmailnode) {
            string mail = it.first;
            int node = dsu.findUpar(it.second);

            mapnodemails[node].push_back(mail);
        }

        vector<vector<string>> res;

        for(auto &it : mapnodemails) {
            int node = it.first;
            vector<string> mails = it.second;

            vector<string> temp;
            temp.push_back(accounts[node][0]);

            sort(mails.begin(), mails.end());

            for(auto mail : mails) {
                temp.push_back(mail);
            }

            res.push_back(temp);
        }

        return res;

    }
};