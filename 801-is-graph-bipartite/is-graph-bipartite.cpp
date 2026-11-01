class Solution {
    bool dfs(int node,int color,auto &graph,vector<int> &vis){
        vis[node] = color;

        for(int x : graph[node]){
            if(vis[x]){
                if(vis[x] == color){
                    return false;
                }
            }
            else{
                
                int adjCol = color == 1 ? 2 : 1;
                
                if(!dfs(x,adjCol,graph,vis)){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> vis(n);

        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(!dfs(i,1,graph,vis)){
                    return false;
                }
            }
        }

        return true;
    }
};