class Solution {
    bool bfs(vector<vector<int>> &graph,queue<pair<int,int>> &q,auto &vis){

        while(!q.empty()){
            pair<int,int> p = q.front();
            int node = p.first;
            int color = p.second;
            q.pop();

            for(int x : graph[node]){
                if(vis[x]){
                    if(vis[x] == color){
                        return false;
                    }
                }
                else{
                    int secCol = 0;
                    if(color == 1) secCol = 2;
                    else secCol = 1;

                    q.push({x,secCol}); 
                    vis[x] = secCol;
                }
            }
        }

        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> vis(n);

        queue<pair<int,int>> q;

        for(int i=0; i<n; i++){
            if(!vis[i]){
                vis[i] = 1;
                q.push({i,1});
                
                if(!bfs(graph,q,vis)){
                    return false;
                }
            }
        }

        return true;
    }
};