class Solution {
    int gcd(int a, int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefixGcd(n);

        int max = nums[0];

        for(int i=0; i<n; i++){
            if(nums[i]>max) max = nums[i];
            prefixGcd[i] = gcd(max,nums[i]);
        }

        sort(prefixGcd.begin(),prefixGcd.end());

        long long sum = 0;
        int i = 0;
        int j = n-1;

        while(i<j){
            sum += gcd(prefixGcd[i],prefixGcd[j]);
            i++;
            j--;
        }

        return sum;
    }
};