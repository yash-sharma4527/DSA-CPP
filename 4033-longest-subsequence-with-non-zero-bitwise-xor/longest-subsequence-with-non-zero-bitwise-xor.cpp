class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        vector<int> zeros(n,0);

        if(nums == zeros) return 0;

        int x = 0;

        for(int val : nums){
            x = x^val;
        }

        if(x) return n;
        else return n-1;
    }
};