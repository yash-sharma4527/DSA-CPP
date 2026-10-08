class Solution {
    void solve(vector<int>& nums,int i,vector<int> sub,auto &st){
        if(i == nums.size()){
            st.insert(sub);
            return;
        }

        //exclude
        solve(nums,i+1,sub,st);

        //include
        sub.push_back(nums[i]);
        solve(nums,i+1,sub,st);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> st;

        vector<int> sub;

        sort(nums.begin(),nums.end());

        solve(nums,0,sub,st);

        vector<vector<int>> ans(begin(st),end(st));

        return ans;
    }
};