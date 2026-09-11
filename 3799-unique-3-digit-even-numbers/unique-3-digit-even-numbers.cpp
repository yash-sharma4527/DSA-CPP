class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();

        int seen[1000] = {0};

        int count = 0;

        for(int i=0; i<n; i++){

            if(digits[i]%2 != 0) continue;

            for(int j=0; j<n; j++){

                if(j == i) continue;

                for(int k=0; k<n; k++){
                    if(k==i || k==j || digits[k] == 0) continue;

                    int ans = digits[k]*100 +
                              digits[j]*10 +
                              digits[i];

                    if(seen[ans] == 0){
                        count++;
                        seen[ans] = 1;
                    }
                }
            }
        }

        return count;
    }
};