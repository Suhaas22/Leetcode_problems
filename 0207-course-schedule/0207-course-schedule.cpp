class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // building graph
        for(auto &pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];

            adj[prereq].push_back(course);
            indegree[course]++;
        }

        queue<int> q;
        
        //pushing the initial elements with indegree 0
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        int cnt = 0;

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;

            for(int el : adj[node]) {
                indegree[el]--;

                if(indegree[el] == 0) {
                    q.push(el);
                }
            }
        }

        return cnt == numCourses;
    }
};