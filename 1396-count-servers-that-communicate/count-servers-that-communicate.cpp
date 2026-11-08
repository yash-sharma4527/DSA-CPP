class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        unordered_map<int,int> row,col;

        int n = grid.size();
        int m = grid[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]){
                    row[i]++;
                    col[j]++;
                }
            }
        }

        int count = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]){
                    row[i]--;
                    col[j]--;

                    if(row[i] || col[j]){
                        count++;
                    }

                    row[i]++;
                    col[j]++;
                }
            }
        }

        return count;
    }
};