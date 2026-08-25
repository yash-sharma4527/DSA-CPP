class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s;

        for(int val:nums){
            s.insert(val);
        }

        int m = k;
        int i = 1;

        while(true){
           if(s.find(m) == s.end()){
            return m;
           }
           else{
               i++;
               m = k*i;
           }
        }

        return -1;
    }
};