class Solution {
    typedef pair<int,int> P;

    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,-1,1};

    void bfs(auto &mat,auto &vis,auto &q,auto &ans){

        int cnt = 1;
        while(!q.empty()){
            int n = q.size();

            for(int i=0; i<n; i++){
               P p = q.front();
               q.pop();

               for(int k=0; k<4; k++){
                int nr = p.first + dr[k];
                int nc = p.second + dc[k];

                if(nr < mat.size() && nr >= 0 && nc < mat[0].size() && nc >= 0
                && vis[nr][nc] == 0){
                    q.push({nr,nc});
                    ans[nr][nc] = cnt;
                    vis[nr][nc] = 1;
                }
               }
            }

            cnt++;
        }
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> ans(m,vector<int>(n,0));

        vector<vector<bool>> vis(m,vector<bool>(n,0));

        queue<P> q;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }

        bfs(mat,vis,q,ans);

        return ans;
    }
};