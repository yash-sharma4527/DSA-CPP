class Solution {
public:
    string reverseWords(string s) {

        int k = 0;
         
        for(int i=0; i<s.size(); i++){

            if(s[i] == ' ' && i < s.length()-1){
                reverse(s.begin()+k,s.begin()+i);
                k = i+1;
            }

            if(i == s.length()-1){
                reverse(s.begin()+k,s.begin()+i+1);
            }

        }

        return s;
    }
};