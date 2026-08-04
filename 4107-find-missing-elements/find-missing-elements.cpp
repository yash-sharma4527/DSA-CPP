class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int min = INT_MAX;
        int max = INT_MIN;

        unordered_map<int,int> mp;

        vector<int> ans;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]<min) min = nums[i];
            if(nums[i]>max) max = nums[i];

            mp[nums[i]]++;
        }

        for(int i=min; i<max; i++){
            if(mp.find(i) == mp.end()){
                 ans.push_back(i);
            }
        }

        return ans;
    }
};