class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        int carry = 1;

        for(int i=n-1; i>=0; i--){
            if(digits[i]<9){
                digits[i] = digits[i] + carry;
                carry = 0;
                break;
            }

            else{
                digits[i] = 0;
            }
        }

        if(carry){
            digits.push_back(1);
            reverse(digits.begin(),digits.end());
        }

        return digits;
    }
};