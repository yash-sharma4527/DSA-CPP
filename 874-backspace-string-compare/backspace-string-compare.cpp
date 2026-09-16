class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string str1,str2;

        for(char ch : s){
            if(ch == '#'){
               if(!str1.empty()){
                str1.pop_back();
               }
            }
            else{
                str1.push_back(ch);
            }
        }

        for(char ch : t){
            if(ch == '#'){
               if(!str2.empty()){
                str2.pop_back();
               }
            }
            else{
                str2.push_back(ch);
            }
        }

        return str1 == str2;
    }
};