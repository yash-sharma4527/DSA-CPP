class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        vector<int> ans;

        int hash1[1001] = {0};

        for(int i=0; i<nums1.size(); i++){
            hash1[nums1[i]] = 1;
        }

        for(int i=0; i<nums2.size(); i++){
            if(hash1[nums2[i]]){
                ans.push_back(nums2[i]);
                hash1[nums2[i]] = 0;
            }
        }

        return ans;
    }
};