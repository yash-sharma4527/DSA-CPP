class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
       int hash[2001] = {0};

       for(int i=0; i<arr.size(); i++){
            hash[arr[i]+1000]++;
       } 

       unordered_set<int> s;

       for(int i=0; i<2001; i++){
            if(hash[i]==0) continue;

            if(s.find(hash[i]) != s.end()){
                return false;
            }
            
            s.insert(hash[i]);
       }

       return true;
    }
};