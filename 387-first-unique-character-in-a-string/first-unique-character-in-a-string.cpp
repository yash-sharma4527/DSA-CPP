class Solution {
public:
    int firstUniqChar(string s) {
        int hash[26] = {0};

        unordered_map<char,int> idx;

        queue<char> q;

        for(int i=0; i<s.size(); i++){
            char ch = s[i];

            hash[ch-'a']++;

            idx[ch] = i;

            q.push(ch);

        }

        while(!q.empty()){
            if(hash[q.front()-'a'] == 1){
                return idx[q.front()];
            }
            else{
                q.pop();
            }
        }

        return -1;
    }
};