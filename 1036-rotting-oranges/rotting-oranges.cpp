class Solution {
    void bfs(vector<vector<int>> &grid,queue<pair<int,int>> &q,int &time,int &fresh){

        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,-1,1};

        while(!q.empty()){
            int n = q.size();

            for(int i=0; i<n; i++){
                pair<int,int> p = q.front();
                q.pop();

                for(int k=0; k<4; k++){
                    int nr = p.first + dr[k];
                    int nc = p.second + dc[k];

                    if(nr < grid.size() && nr >= 0 && nc < grid[0].size() &&
                    nc >= 0 && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        q.push({nr,nc});
                        fresh--;
                    }
                }

            }

            if(!q.empty()){
                time++;
            }
        }
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;

        int fresh = 0;
        int time = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        bfs(grid,q,time,fresh);

        if(fresh) return -1;

        return time;
    }
};