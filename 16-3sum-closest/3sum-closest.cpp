class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();

        sort(nums.begin(),nums.end());

        int closest = 0;
        int check = INT_MAX;

        for(int i=0; i<n-2; i++){

            int j = i+1;
            int k = n-1;

            while(j<k){

                int sum = nums[i] + nums[j] + nums[k];

                if(abs(sum-target) < check){
                    closest = sum;
                    check = abs(sum-target);
                }

                if(sum == target){
                    return sum;
                }

                else if(sum < target){
                    j++;
                }

                else{
                    k--;
                }
            }
        }

        return closest;
    }
};