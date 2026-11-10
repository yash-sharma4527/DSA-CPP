class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int freq[101] = {0};

        int sum = 0;

        for(int i=0; i<nums.size(); i++){
            if(freq[nums[i]] == 0){
                sum += nums[i];
            }

            else if(freq[nums[i]] == 1){
                sum -= nums[i];
            }

            freq[nums[i]]++;
        }

        return sum;
    }
};