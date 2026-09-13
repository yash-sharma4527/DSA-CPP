class Solution {
    int countOverlaps(auto &A, auto &B, int row, int col){
        int n = A.size();

        int count = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){

                if(i+row < 0 || i+row >= n || j+col < 0 || j+col >=n){
                    continue;
                }

                if(A[i][j]==1 && B[i+row][j+col] == 1){
                    count++;
                }
            }
        }

        return count;
    }
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();

        int maxCount = 0;

        for(int row = -n+1; row < n; row++){
            for(int col = -n+1; col < n; col++){
                int count = countOverlaps(A,B,row,col);
                
                maxCount = max(count,maxCount);
            }
        }

        return maxCount;
    }
};