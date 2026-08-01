class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;

        int n = nums.size();

        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }

        int m = n/2;

        auto it = mp.begin();

        while(it != mp.end()){
            if((it->second) > m){
                return it->first;
            }
            it++;
        }

        return 0;
    }
};