class Solution {
    void reverse(vector<vector<int>>& grid,int i, int j, int r, int c){
        while(i<j){
            swap(grid[i/c][i%c],grid[j/c][j%c]);
            i++;
            j--;
        }
    }
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int r = grid.size();
        int c = grid[0].size();

        int n = r*c ;

        if(k==0) return grid;

        k = k%n;

        reverse(grid,0,n-1,r,c);
        reverse(grid,0,k-1,r,c);
        reverse(grid,k,n-1,r,c);

        return grid;
    }
};