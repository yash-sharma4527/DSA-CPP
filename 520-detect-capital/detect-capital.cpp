class Solution {
    bool isCapital(char ch){
        if(ch >= 'A' && ch <= 'Z'){
            return true;
        }

        return false;
    }
public:
    bool detectCapitalUse(string word) {
        int n = word.length();

        if(n == 1){
            return true;
        }

        bool first = isCapital(word[0]);
        bool allCap = true;
        bool nextCap = false;

        for(int i=1; i<n; i++){
            char ch = word[i];

            if(isCapital(ch)){
                nextCap = true;
            }
            else{
                allCap = false;
            }
        }

        if(first && allCap) return true;

        else if(first && !nextCap) return true;

        else if(!first && !nextCap) return true;

        return false;
    }
};