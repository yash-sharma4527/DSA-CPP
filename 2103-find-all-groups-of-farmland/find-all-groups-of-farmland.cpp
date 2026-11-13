class Solution {
    void dfs(int i,int j,int &r,int &c,auto &land){
        if(i >= land.size() || j >= land[0].size() || land[i][j] == 0){
            return;
        }

        if(i > r || j > c){
            r = i;
            c = j;
        }

        land[i][j] = 0;

        dfs(i+1,j,r,c,land);
        dfs(i,j+1,r,c,land);
    }
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;

        for(int i=0; i<land.size(); i++){
            for(int j=0; j<land[0].size(); j++){
                if(land[i][j] == 1){
                    vector<int> farm(4);
                    farm[0] = i;
                    farm[1] = j;

                    int r = i , c = j;

                    dfs(i,j,r,c,land);

                    farm[2] = r;
                    farm[3] = c;

                    ans.push_back(farm);
                }
            }
        }

        return ans;
    }
};