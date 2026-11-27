class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> diff = grid;

        vector<int> row1(m,0);
        vector<int> col1(n,0);

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]){
                    row1[i]++;
                    col1[j]++;
                }
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                diff[i][j] = 2*row1[i] + 2*col1[j] - m - n;
            }
        }

        return diff;
    }
};