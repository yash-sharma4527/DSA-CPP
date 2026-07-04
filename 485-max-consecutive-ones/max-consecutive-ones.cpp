class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int ans = 0;
        int maxAns = 0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]==1){
                count++;
                ans = count;
            }
            else{
                count = 0;
            }
            if(ans>maxAns) maxAns = ans;
        }

        return maxAns;
    }
};