class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;

        if(n==k){
            int maxi = -1;

            for(int i=0; i<n; i++){
                maxi = max(maxi,nums[i]);
            }

            return maxi;
        }

        for(int i=0; i < n-k+1; i++){
            for(int j=i; j<i+k; j++){
                mp[nums[j]]++;
            }
        }

        int ans = -1;

        for(auto it = mp.begin(); it != mp.end(); it++){
            if(it->second == 1 && it->first > ans){
                ans = it->first;
            }
        }

        return ans;
    }
};