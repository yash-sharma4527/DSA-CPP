class Solution {
    bool dfs(int i,int j,auto &grid1,auto &grid2){
        if(i >= grid2.size() || j >= grid2[0].size() || i < 0 || j < 0 || grid2[i][j] == 0){
            return true;
        }

        bool flag = grid2[i][j] == grid1[i][j];

        grid2[i][j] = 0;

        bool up = dfs(i+1,j,grid1,grid2);
        bool down = dfs(i-1,j,grid1,grid2);
        bool left = dfs(i,j-1,grid1,grid2);
        bool right = dfs(i,j+1,grid1,grid2);

        if(!flag) return false;

        return up && down && left && right;
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count = 0;

        for(int i=0; i<grid2.size(); i++){
            for(int j=0; j<grid2[0].size(); j++){
                if(grid2[i][j] == 1){
                    if(dfs(i,j,grid1,grid2)){
                        count++;
                    }
                }
            }
        }

        return count;
    }
};