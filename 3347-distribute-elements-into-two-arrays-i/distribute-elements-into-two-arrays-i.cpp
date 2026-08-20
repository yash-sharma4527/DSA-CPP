class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> result(n);

        vector<int> arr1(n);
        vector<int> arr2(n);

        arr1[0] = nums[0];
        arr2[0] = nums[1];

        int a = 0 , b = 0;

        for(int i=2; i<n; i++){
            if(arr1[a]>arr2[b]){
                arr1[++a] = nums[i];
            }
            else{
                arr2[++b] = nums[i];
            }
        }

        int i = 0;

        while(i<=a){
            result[i] = arr1[i];
            i++;
        }

        int p = 0;

        while(i<n){
            result[i++] = arr2[p++];
        }

        return result;
    }
};