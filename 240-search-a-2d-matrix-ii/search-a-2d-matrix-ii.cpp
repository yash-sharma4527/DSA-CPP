class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int r = matrix.size();
        int c = matrix[0].size();
        
        int stRow = 0;
        int endCol = matrix[0].size()-1;

        while(stRow<r && endCol>=0){
            int element = matrix[stRow][endCol];

            if(target==element) return true;

            else if(target>element) stRow++;

            else endCol--;
        }

        return false;
    }
};