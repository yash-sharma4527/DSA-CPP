class Solution {
    vector<vector<int>> result;

    void solve(vector<int> &ans,int start,int n,int k){
        if(k == 0){
            result.push_back(ans);
            return;
        }

        for(int i=start; i<=n; i++){
            ans.push_back(i); 
            solve(ans,i+1,n,k-1);
            ans.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> ans;

        solve(ans,1,n,k);

        return result;
    }
};