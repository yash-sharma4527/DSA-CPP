class Solution {
public:
    bool checkString(string s) {
        int inA = -1;
        int inB = s.size();

        bool flagB = 1;

        for(int i=0; i<s.size(); i++){
            if(s[i] == 'a'){
                inA = i;
            }

            else if(flagB){
                inB = i;
                flagB = 0;
            }
        }

        return inA < inB;
    }
};