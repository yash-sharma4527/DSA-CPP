class Solution {
public:
    int firstOccurence(vector<int>& nums,int target){
        int s = 0 , e = nums.size()-1;
        int mid = s + (e-s)/2;

        int position = -1;

        while(s<=e){
            if(nums[mid]==target){
                position = mid;
                e = mid-1;
            }
            else if(nums[mid]>target) e = mid-1;

            else s = mid+1;

            mid = s + (e-s)/2;
        }
        return position;
    }
    int lastOccurence(vector<int>& nums,int target){
        int s = 0 , e = nums.size() - 1;
        int mid = s + (e-s)/2;

        int position = -1;

        while(s<=e){
            if(nums[mid]==target){
                position=mid;
                s = mid+1;
            }
            
            else if(nums[mid]<target) s = mid+1;

            else e = mid - 1;

            mid = s + (e-s)/2;
        }

        return position;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n1 = firstOccurence(nums,target);
        int n2 = lastOccurence(nums,target);

        return {n1,n2};
    }
};