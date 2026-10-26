class Solution {
    vector<int> dr = {-1,1,0,0};
    vector<int> dc = {0,0,-1,1};

    void bfs(vector<vector<char>> &grid,int i,int j){
        queue<pair<int,int>> q;

        q.push({i,j});
        grid[i][j] = '0';

        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();

            for(int k=0; k<4; k++){
                int nr = p.first + dr[k];
                int nc = p.second + dc[k];

                if(nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && grid[nr][nc] != '0'){
                    q.push({nr,nc});
                    grid[nr][nc] = '0';
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int islands = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1'){
                    bfs(grid,i,j);
                    islands++;
                }
            }
        }

        return islands;
    }
};