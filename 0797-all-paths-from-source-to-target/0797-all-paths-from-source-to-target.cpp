class Solution {
    private:
    vector<vector<int>> res;

    void dfs(int node, int n, vector<int> & path, vector<vector<int>> & graph){
        if(node == n - 1){
            res.push_back(path);
            return;
        }

        int currnode  = node;

        for(int adjnode : graph[currnode]) {
            path.push_back(adjnode);
            dfs(adjnode, n, path, graph);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> path;
        path.push_back(0);

        dfs(0, n, path, graph);

        return res;
    }
};