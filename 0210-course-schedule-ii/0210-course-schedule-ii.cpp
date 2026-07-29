class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // building the graph
        for(auto &pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];

            adj[prereq].push_back(course);
            indegree[course]++;
        }

        queue<int> q;

        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> order;
        int cnt = 0;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;
            order.push_back(node);

            for(int el : adj[node]) {
                indegree[el]--;

                if(indegree[el] == 0) {
                    q.push(el);
                }
            }
        }

        if(cnt == numCourses){
            return order;
        }

        return {};
    }
};