class Solution {
    int pivotIdx(vector<int>& nums){
        int ans = 0;
        int s = 0 , e = nums.size()-1;

        while(s<=e){
            int mid = s + (e-s)/2;

            if(nums[mid]>=nums[0]){
                s = mid + 1;
            }

            else{
                ans = mid ;
                e = mid - 1;
            }
        }
        return ans;
    }
    
    int binarySearch(vector<int>& nums,int s,int e,int target){
        
        while(s<=e){
            int mid = s + (e-s)/2;

            if(nums[mid]==target) return mid;

            else if(nums[mid]>target) e = mid - 1;

            else s = mid + 1;
        }

        return -1;
    }

public:
    int search(vector<int>& nums, int target) {
        int pivot = pivotIdx(nums);

        int line1 = binarySearch(nums,0,pivot-1,target);

        int line2 = binarySearch(nums,pivot,nums.size()-1,target);

        if(line1 != -1) return line1;
        else if(line2 != -1) return line2;
        else return -1;
    }
};