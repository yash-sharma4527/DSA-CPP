class Solution {
public:
    int maxProduct(int n) {
        int digit;
        
        int max = INT_MIN ;
        int sMax = INT_MIN ;

        while(n != 0){
            digit = n%10;

            if(digit>max){
                sMax = max;
                max = digit;
            }
            
            else if(digit>sMax) {
                sMax = digit;
            }

            n = n/10;
        }

        return max*sMax;
    }
};