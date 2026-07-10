class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min = strs[0].size();

        for(int i=1; i<strs.size(); i++){
            int j = 0;
            while(j < strs[0].size() && j < strs[i].size()){
                if(strs[0][j]==strs[i][j]) j++;
                else break;
            }
            if(j < min) min = j;
        }

        return strs[0].substr(0,min);
    }
};