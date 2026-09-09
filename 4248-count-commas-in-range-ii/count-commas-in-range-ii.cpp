class Solution {
public:
    long long countCommas(long long n) {
        long long curr = 1000;
        long long ans = 0;

        while(curr <= n){
            ans += n - curr + 1;
            curr = curr*1000;
        }

        return ans;
    }
};