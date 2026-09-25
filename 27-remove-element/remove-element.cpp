class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int nv = 0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] != val){
                nums[nv] = nums[i];
                nv++;
            }
        }

        return nv;
    }
};