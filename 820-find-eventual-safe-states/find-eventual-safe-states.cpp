class Solution {
    bool dfs(int i,vector<vector<int>> &graph,vector<int> &vis){
        vis[i] = 1;

        if(graph[i].size() == 0){
            vis[i] = 2;
            return true;
        }

        for(int x : graph[i]){
            if(!vis[x]){
                if(!dfs(x,graph,vis)){
                    return false;
                }
            }

            else if(vis[x] == 1){
                return false;
            }
        }

        vis[i] = 2;
        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> vis(n,0);

        vector<int> ans;

        for(int i=0; i<n; i++){
            if(vis[i] == 2){
                ans.push_back(i);
            }

            else if(!vis[i]){
                if(dfs(i,graph,vis)){
                    ans.push_back(i);
                }
            }
        }

        return ans;
    }
};