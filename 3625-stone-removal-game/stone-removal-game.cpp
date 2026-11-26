class Solution {
public:
    bool canAliceWin(int n) {
        int t = 10;
        bool alice = true;

        while(true){
            if(n < t){
                if(alice){
                    return false;
                }

                else return true;
            }

            n = n - t;
            t--;
            alice = !alice;
        }
    }
};