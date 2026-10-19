class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int small = 0;
        int n = nums.size();
        int count = 0;

        for(int i=0; i<n; i++){
            if(nums[i] == target){
                count++;
            }

            else if(nums[i] < target){
                small++;
            }
        }

        vector<int> ans;

        int i = count;

        while(i != 0){
            ans.push_back(small++);
            i--;
        }

        return ans;
    }
};