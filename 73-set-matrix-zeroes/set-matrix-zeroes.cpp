class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> vec;

        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j]==0){
                    vec.push_back({i,j});
                }
            }
        }

        int n = vec.size();

        for(int i=0; i<matrix.size(); i++){
            int k = 0;
            while(k<n){
                if(vec[k].first == i){
                    for(int j=0; j<matrix[0].size(); j++){
                        matrix[i][j] = 0;
                    }
                }
                k++;
            }
        }

        for(int j=0; j<matrix[0].size(); j++){
            int k = 0;
            while(k<n){
                if(vec[k].second == j){
                    for(int i=0; i<matrix.size(); i++){
                        matrix[i][j] = 0;
                    }
                }
                k++;
            }
        }
    }
};