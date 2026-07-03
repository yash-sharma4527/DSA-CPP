class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int a ;//repeated value
        int b;//missing value;

        int N = n*n;

        int expectedSum = (N*(N+1))/2;
        int actualSum = 0;

        unordered_set<int> s;

        for(auto &row : grid){
            for(int element : row){
                if(s.find(element) != s.end()){
                    a = element;
                }
                actualSum += element;

                s.insert(element);
            }
        }

        b = expectedSum - actualSum + a;

        return {a,b};
    }
};