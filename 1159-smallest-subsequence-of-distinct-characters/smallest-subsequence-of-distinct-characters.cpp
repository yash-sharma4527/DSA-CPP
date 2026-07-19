class Solution {
public:
    string smallestSubsequence(string s) {

        string ans = "";
        
        int n = s.size();

        vector<bool> taken(26,false);

        vector<int> lastIndex(26);

        for(int i=0; i<n; i++){
            char ch = s[i];
            lastIndex[ch-'a'] = i;
        }

        for(int i=0; i<n; i++){
            char ch = s[i];

            if(taken[ch-'a']) continue;

            while(ans.size()>0 && ch < ans.back() && lastIndex[ans.back()-'a'] > i){
                taken[ans.back()-'a'] = false;
                ans.pop_back();
            }
            
            taken[ch-'a'] = true;
            ans.push_back(ch);
        }

        return ans;
    }
};