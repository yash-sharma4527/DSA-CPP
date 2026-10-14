class Solution {
    vector<vector<int>> result;

    void solve(vector<int> &ans,int n,int k,int i){
        if(k == 0){
            result.push_back(ans);
            return;
        }

        if(i > n){
            return;
        }

        ans.push_back(i); // include
        solve(ans,n,k-1,i+1);
        ans.pop_back(); 
        solve(ans,n,k,i+1); // exclude;
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> ans;

        solve(ans,n,k,1);

        return result;
    }
};