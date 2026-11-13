class Solution {
    void dfs(int i,int j,int &fish,vector<vector<int>> &grid){
        if(i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0 || 
        grid[i][j] == 0){
            return;
        }

        fish += grid[i][j];
        grid[i][j] = 0;

        dfs(i+1,j,fish,grid);
        dfs(i-1,j,fish,grid);
        dfs(i,j+1,fish,grid);
        dfs(i,j-1,fish,grid);
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int ans = 0;

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] > 0){
                    int fish = 0;
                    dfs(i,j,fish,grid);

                    ans = max(ans,fish);
                }
            }
        }

        return ans;
    }
};