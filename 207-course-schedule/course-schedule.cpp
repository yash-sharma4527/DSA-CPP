class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> adj[n];

        for(auto &v : prerequisites){
            adj[v[1]].push_back(v[0]);
        }

        vector<int> indegree(n,0);

        for(int i=0; i<n; i++){
            for(int x : adj[i]){
                indegree[x]++;
            }
        }

        queue<int> q;

        int cnt = 0;

        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int x : adj[node]){
                indegree[x]--;
                if(indegree[x] == 0){
                    q.push(x);
                }
            }

            cnt++;
        }

        if(cnt == n) return true;

        return false;
    }
};