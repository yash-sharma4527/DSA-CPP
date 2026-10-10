class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();

        vector<int> diff(n); 

        int maxi = 0;

        for(int i=0; i<n; i++){
            diff[i] = abs(nums1[i] - nums2[i]);
            maxi = max(maxi,diff[i]);
        }

        vector<int> hash(maxi+1,0);

        for(int x : diff){
            hash[x]++;
        }

        int k = k1 + k2;

        for(int i = maxi; i> 0 && k > 0; i--){
            if(hash[i] == 0) continue;

            int countOp = min(k,hash[i]);
            
            hash[i] -= countOp;

            hash[i-1] += countOp;

            k -= countOp;
        }

        long long sum = 0;

        for(long long i=0; i<=maxi ; i++){
            sum += hash[i]*i*i;
        }

        return sum;
    }
};