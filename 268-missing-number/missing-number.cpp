class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int expectedSum = n*(n+1)/2;

        bool zero = false;

        int sum = 0;

        for(int i=0; i<n; i++){
            if(nums[i] == 0) zero = true;
            sum += nums[i];
        }

        if(!zero) return 0;

        return expectedSum - sum;
    }
};