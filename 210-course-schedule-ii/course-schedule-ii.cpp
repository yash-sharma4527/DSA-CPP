class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;

        vector<int> graph[n];//adjacency list

        for(auto &v : prerequisites){
            graph[v[1]].push_back(v[0]);
        }

        vector<int> indegree(n,0);

        for(auto &l : graph){
            for(int x : l){
                indegree[x]++;
            }
        }

        queue<int> q;

        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int x : graph[node]){
                indegree[x]--;

                if(indegree[x] == 0){
                    q.push(x);
                }
            }

            ans.push_back(node);
        }

        if(ans.size() != n) return {};

        return ans;
    }
};