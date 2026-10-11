class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();

        int closest = 0;
        int check = INT_MAX;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    int sum = nums[i] + nums[j] + nums[k];

                    if(abs(sum - target) < check){
                        closest = sum;
                        check = abs(sum-target);
                    }
                }
            }
        }

        return closest;
    }
};