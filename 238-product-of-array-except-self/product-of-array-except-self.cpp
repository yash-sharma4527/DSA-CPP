class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> suffix(n);

        int s = 1;

        for(int i=n-1; i>=0; i--){
            s *= nums[i];
            suffix[i] = s;
        }

        vector<int> result;
        int prod = 1;

        result.push_back(suffix[1]);

        for(int i=1; i<n-1; i++){
            prod *= nums[i-1];

            result.push_back(prod*suffix[i+1]);
        }

        prod *= nums[n-2];

        result.push_back(prod);

        return result;
    }
};