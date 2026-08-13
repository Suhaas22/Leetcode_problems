class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        
        int n = graph.size();

        vector<vector<int>> reversegraph(n);

        vector<int> outdegree(n, 0);

        for(int i = 0; i < n; i++) {

            outdegree[i] = graph[i].size();

            for(int v : graph[i]) {
                reversegraph[v].push_back(i);
            }
        }

        queue<int> q;

        for(int i = 0; i < n; i++) {
            if(outdegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> safe;

        while(!q.empty()) {

            int node = q.front();

            safe.push_back(node);

            q.pop();

            for(int prev : reversegraph[node]) {
                outdegree[prev]--;

                if(outdegree[prev] == 0){
                    q.push(prev);
                }
            }
        }

        sort(safe.begin(), safe.end());

        return safe;


    }
};