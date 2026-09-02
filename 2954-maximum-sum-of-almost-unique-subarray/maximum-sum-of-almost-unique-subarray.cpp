class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        int n = nums.size();

        long long windowSum = 0;
        long long maxSum = 0;

        unordered_map<int,int> mp;

        for(int i=0; i<k; i++){
            windowSum += nums[i];
            mp[nums[i]]++;
        }

        if(mp.size()>=m){
            maxSum = max(maxSum,windowSum);
        }

        int del = 0;

        for(int i=k; i<n; i++){
           windowSum = windowSum + nums[i] - nums[del] ;

           mp[nums[i]]++;
           mp[nums[del]]--;

           if(mp[nums[del]]==0){
            mp.erase(nums[del]);
           }

           if(mp.size() >= m){
            maxSum = max(maxSum,windowSum);
           }

           del++;
        }

        return maxSum;
    }
};