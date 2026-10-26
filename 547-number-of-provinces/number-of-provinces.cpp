class Solution {
    void dfs(int node,vector<vector<int>> &adj,vector<bool> &vis){
        vis[node] = 1;

        for(int x : adj[node]){
            if(!vis[x]){
                dfs(x,adj,vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> adj(n+1);

        vector<bool> vis(n+1,0);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }

        int ans = 0;

        for(int i=1; i<=n; i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                ans++;
            }
        }

        return ans;
    }
};