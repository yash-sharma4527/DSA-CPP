class Solution {
    void powerset(vector<int> &nums,vector<int> output,int i,vector<vector<int>> &ans){
        if(i>=nums.size()){
            ans.push_back(output);
            return;
        }

        //exclude
        powerset(nums,output,i+1,ans);

        //include
        output.push_back(nums[i]);
        powerset(nums,output,i+1,ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;

        powerset(nums,output,index,ans);

        return ans;
    }
};