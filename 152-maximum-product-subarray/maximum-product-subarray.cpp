class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int mini = nums[0];
        int maxi = nums[0];

        for(int i=1; i<nums.size(); i++){
            int x = nums[i];

            int currMin = min(x,min(x*mini,x*maxi));
            int currMax = max(x,max(x*mini,x*maxi));

            ans = max(ans,currMax);

            mini = currMin;
            maxi = currMax;
        }

        return ans;
    }
};