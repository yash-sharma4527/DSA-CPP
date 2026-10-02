class Solution {
    void solve(vector<string> &ans,string &s,int i,int j,int n){
        if(s.size() == n*2){
            ans.push_back(s);
            return;
        }

        if(i != n){
            s.push_back('(');
            solve(ans,s,i+1,j,n);
            s.pop_back();
        }

        if(j < i){
            s.push_back(')');
            solve(ans,s,i,j+1,n);
            s.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        string s = "(";

        int i = 1;
        int j = 0;

        solve(ans,s,i,j,n);

        return ans;
    }
};