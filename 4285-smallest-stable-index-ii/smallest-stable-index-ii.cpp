class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        int* minArr = new int[n];

        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(int i=n-1; i>=0; i--){
            mini = min(mini,nums[i]);
            minArr[i] = mini;
        }

        int ans = -1;

        for(int i=0; i<n; i++){
            maxi = max(maxi,nums[i]);

            if(maxi-minArr[i] <= k){
                ans = i;
                break;
            }
        }

        return ans;
    }
};