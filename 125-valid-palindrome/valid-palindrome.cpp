class Solution {
public:
    bool isAlphanumeric(char ch){
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')) return true;
        return false;
    }
    char toLowerCase(char ch){
        if(ch>='A' && ch<='Z'){
            return ch-'A'+'a';
        }
        return ch;
    }
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;

        while(i<j){
            while(i<j && !(isAlphanumeric(s[i]))) i++;
            while(i<j && !(isAlphanumeric(s[j]))) j--;

            if(toLowerCase(s[i])!=toLowerCase(s[j]))
                return false;

            i++;
            j--;
        } 

        return true;
    }
};