class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();

        int inc = 1;
        int dec = 1;

        for(int i=0; i<n; i++){
            int incii = 0;
            for(int j = i; j<n-1; j++){
                if(nums[j] < nums[j+1]){
                    incii++;
                }
                else{
                    break;
                }
            }

            inc = max(inc,incii+1);
        }

        for(int i=0; i<n; i++){
            int decii = 0;
            for(int j = i; j<n-1; j++){
                if(nums[j] > nums[j+1]){
                    decii++;
                }
                else{
                    break;
                }
            }

            dec = max(dec,decii+1);
        }

        return max(inc,dec);
    }
};