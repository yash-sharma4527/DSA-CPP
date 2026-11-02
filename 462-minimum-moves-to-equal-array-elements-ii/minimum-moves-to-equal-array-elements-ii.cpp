class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int n = nums.size();
        int mid = n/2;

        int lsum = 0;
        int lcount = 0;

        for(int i=0; i<mid; i++){
            lsum += nums[i];
            lcount++;
        }

        int rsum = 0;
        int rcount = 0;

        for(int i=mid+1; i<n; i++){
            rsum += nums[i];
            rcount++;
        }

        int expectLSum = nums[mid]*lcount;
        int expectRSum = nums[mid]*rcount;

        int moves = (expectLSum - lsum) + (rsum - expectRSum);

        return moves;
    }
};