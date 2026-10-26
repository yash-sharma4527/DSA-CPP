class Solution {
    void dfs(auto &grid,long long &sum,int i,int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()
        || grid[i][j] == 0){
            return;
        }

        sum += grid[i][j];
        grid[i][j] = 0;

        dfs(grid,sum,i+1,j);
        dfs(grid,sum,i-1,j);
        dfs(grid,sum,i,j+1);
        dfs(grid,sum,i,j-1);
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                long long sum = 0;

                if(grid[i][j]){
                    dfs(grid,sum,i,j);

                    if(sum % k == 0) ans++;
                }
            }
        }

        return ans;
    }
};