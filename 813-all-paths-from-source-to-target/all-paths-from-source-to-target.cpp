class Solution {
    void dfs(int node,auto &graph,vector<int> &path,auto &ans){
        path.push_back(node);

        if(node == graph.size() - 1){
            ans.push_back(path);
            path.pop_back();
            return;
        }

        for(int x : graph[node]){
            dfs(x,graph,path,ans);
        }

        path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;

        vector<int> path;

        dfs(0,graph,path,ans);

        return ans;
    }
};