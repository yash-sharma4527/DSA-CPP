class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;

        for(int i=0; i<s.length(); i++){
            int n = ('a'- s[i]) + 26;
            n = n*(i+1);
            sum += n;
        }

        return sum;
    }
};