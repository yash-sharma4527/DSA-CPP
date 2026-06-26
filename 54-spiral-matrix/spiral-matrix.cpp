class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> ans;
        int r = matrix.size();
        int c = matrix[0].size();

        int count = 0;
        int total = r*c;

        int stRow = 0;
        int endRow = r-1;
        int stCol = 0;
        int endCol = c-1;

        while(count<total){
            //first row print
            for(int i=stCol; count<total && i<=endCol; i++){
                ans.push_back(matrix[stRow][i]);
                count++;
            }
            stRow++;

            //end column print
            for(int i=stRow; count<total && i<=endRow; i++){
                ans.push_back(matrix[i][endCol]);
                count++;
            }
            endCol--;

            //end row print
            for(int i=endCol; i>=stCol && count<total; i--){
                ans.push_back(matrix[endRow][i]);
                count++;
            }
            endRow--;

            //first column print
            for(int i=endRow; i>=stRow && count<total; i--){
                ans.push_back(matrix[i][stCol]);
                count++;
            }
            stCol++;
        }
        return ans;
    }
};