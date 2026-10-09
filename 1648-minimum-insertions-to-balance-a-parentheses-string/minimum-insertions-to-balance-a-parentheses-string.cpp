class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int ans = 0;

        for(int i=0; i<s.size(); i++){

            if(s[i] == '('){
                open++;
            }

            else{
                if(open == 0){
                    open++;
                    ans++;
                }

                if(i+1 < s.size() && s[i+1] == ')'){
                    open--;
                    i++;
                }

                else{
                    ans++;
                    open--;
                }
            }
        }

        return ans + 2*open;
    }
};