class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> result;
        
        for(int i=0; i<m; i++){
            string ans;

            if(i==0){
                for(int j=0; j<n; j++){
                    ans.push_back('.');
                }
            }

            else{
                for(int j=0; j<n-1; j++){
                    ans.push_back('#');
                }

                ans.push_back('.');
            }

            result.push_back(ans);
        }

        return result;
    }
};