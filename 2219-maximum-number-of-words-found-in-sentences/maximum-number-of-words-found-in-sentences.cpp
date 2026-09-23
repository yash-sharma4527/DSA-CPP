class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxi = INT_MIN;

        for(string &s : sentences){
            int count = 0;

            for(char ch : s){
                if(ch == ' '){
                    count++;
                }
            }

            maxi = max(maxi,++count);
        }

        return maxi;
    }
};