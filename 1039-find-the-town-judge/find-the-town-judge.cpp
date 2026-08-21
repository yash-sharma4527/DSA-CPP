class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
       int size = trust.size();

       for(int i=1; i<=n; i++){
        bool flag = true;

        int x = 0;
        for(int j=0; j<size; j++){
            if(trust[j][1]==i){
                x++;
            }
            if(trust[j][0]==i){
                flag = false;
                break;
            }
        }

        if(flag && x==n-1) return i;
    }

    return -1;

    }
};