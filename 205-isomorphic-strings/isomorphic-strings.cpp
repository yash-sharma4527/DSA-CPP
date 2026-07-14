class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mapS , mapT;

        for(int i=0; i<s.size(); i++){
            int ch1 = s[i];
            int ch2 = t[i];

            if((mapS.find(ch1) != mapS.end() && mapS[ch1] != ch2) || (mapT.find(ch2) != mapT.end() && mapT[ch2] != ch1)) return false;

            mapS[ch1] = ch2;
            mapT[ch2] = ch1;
        }

        return true;
    }
};