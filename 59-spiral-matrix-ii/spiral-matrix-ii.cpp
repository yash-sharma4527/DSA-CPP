class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n));

        int total = n*n +1;
        int count = 1;

        int stRow = 0;
        int endRow = n-1;
        int stCol = 0;
        int endCol = n-1;

        while(count<total){
            for(int i=stCol; i<=endCol; i++){
                ans[stRow][i] = count++ ;
            }
            stRow++;

            for(int i=stRow; i<=endRow; i++ ){
                ans[i][endCol] = count++;
            }
            endCol--;

            for(int i=endCol; i>=stCol; i--){
                ans[endRow][i] = count++;
            }
            endRow--;

            for(int i=endRow; i>=stRow; i--){
                ans[i][stCol] = count++;
            }
            stCol++;
        }
        return ans;
    }
};