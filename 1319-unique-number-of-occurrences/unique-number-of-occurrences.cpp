class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
       int hash[2001] = {0};

       for(int i=0; i<arr.size(); i++){
            hash[arr[i]+1000]++;
       } 

       for(int i=0; i<2001; i++){
         for(int j=i+1; j<2001; j++){
            if(hash[i]==hash[j] && hash[i]!=0 && hash[j] != 0) return false;
         }
       }

       return true;
    }
};