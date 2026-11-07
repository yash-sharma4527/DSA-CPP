class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> list1 , list2;

        unordered_set<int> st2;

        for(int i=0; i<nums2.size(); i++){
            st2.insert(nums2[i]);
        }

        unordered_set<int> st1;

        for(int i=0; i<nums1.size(); i++){
            if(!st2.count(nums1[i]) && !st1.count(nums1[i])){
                list1.push_back(nums1[i]);
            }
            st1.insert(nums1[i]);
        }

        st2.clear();

        for(int i=0; i<nums2.size(); i++){
            if(!st1.count(nums2[i]) && !st2.count(nums2[i])){
                list2.push_back(nums2[i]);
                st2.insert(nums2[i]);
            }
        }

        return {list1,list2};
    }
};