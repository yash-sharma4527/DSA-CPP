class Solution {
    void dfs(vector<vector<int>> &grid,int &peri,int i,int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
        grid[i][j] == 0){
            peri++;
            return;
        }

        if(grid[i][j] == -1){
            return;
        }

        grid[i][j] = -1;

        dfs(grid,peri,i+1,j);
        dfs(grid,peri,i-1,j);
        dfs(grid,peri,i,j+1);
        dfs(grid,peri,i,j-1);
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();

        int m = grid[0].size();

        int peri = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]){
                    dfs(grid,peri,i,j);
                    return peri;
                }
            }
        }

        return peri;
    }
};