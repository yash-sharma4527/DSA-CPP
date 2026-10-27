class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> result;

        string row1;

        for(int i=0; i<n; i++){
            row1.push_back('.');
        }

        result.push_back(row1);

        string leftRow ;

        for(int i=0; i<n-1; i++){
            leftRow.push_back('#');
        }

        leftRow.push_back('.');

        for(int i=1; i<m; i++){
            result.push_back(leftRow);
        }

        return result;
    }
};