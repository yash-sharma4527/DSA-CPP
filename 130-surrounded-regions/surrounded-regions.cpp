class Solution {
    void dfs(int i,int j,auto &board,auto &vis){ 
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || 
        board[i][j] == 'X' || vis[i][j]){
            return;
        }

        vis[i][j] = 1;

        dfs(i+1,j,board,vis);
        dfs(i-1,j,board,vis);
        dfs(i,j-1,board,vis);
        dfs(i,j+1,board,vis);
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> vis(m,vector<bool>(n));

        int i = 0;
        int k = m-1;

        for(int j=0; j<n; j++){
            if(board[i][j] == 'O' && !vis[i][j]){
                dfs(i,j,board,vis);
            }
            if(board[k][j] == 'O' && !vis[k][j]){
                dfs(k,j,board,vis);
            }
        }

        int p = 0;
        int q = n-1;

        for(int r=0; r<m; r++){
            if(board[r][p]=='O' && !vis[r][p]){
                dfs(r,p,board,vis);
            }
            if(board[r][q] == 'O' && !vis[r][q]){
                dfs(r,q,board,vis);
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};