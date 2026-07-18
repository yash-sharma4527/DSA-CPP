class Solution {
    int gcd(int a, int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
public:
    int findGCD(vector<int>& nums) {
        int min = INT_MAX;
        int max = INT_MIN;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] > max) max = nums[i];
            if(nums[i] < min) min = nums[i];
        }

        return gcd(max,min);
    }
};