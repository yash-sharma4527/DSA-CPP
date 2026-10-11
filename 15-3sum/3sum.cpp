class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;

        sort(nums.begin(),nums.end());

        for(int i=0; i<nums.size()-2; i++){
            int j = i+1;
            int k = nums.size()-1;

            int first = nums[i];

            while(j < k){
                if(first + nums[j] + nums[k] == 0){
                    st.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }

                else if(first + nums[j] + nums[k] > 0){
                    k--;
                }

                else{
                    j++;
                }
            }
        }

        vector<vector<int>> ans(st.begin(),st.end());

        return ans;
    }
};