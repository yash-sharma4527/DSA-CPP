class Solution {
    void bfs(auto &q,auto &height){

        int dr[4] = {0,0,-1,1};
        int dc[4] = {-1,1,0,0};

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int h = q.front().second;

            for(int i=0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >=0 && nr < height.size() && nc >=0 && nc < height[0].size() && height[nr][nc] == -1){
                    height[nr][nc] = h+1;
                    q.push({{nr,nc},h+1});
                }
            }

            q.pop();
        }
    }
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> height(m,vector<int>(n,-1));

        queue<pair<pair<int,int>,int>> q;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(isWater[i][j] == 1){
                    height[i][j] = 0;
                    q.push({{i,j},0});
                }
            }
        }

        bfs(q,height);

        return height;
    }
};