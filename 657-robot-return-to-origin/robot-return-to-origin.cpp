class Solution {
    bool isOrigin(string &moves, int r, int c, int i){
        if(i >= moves.length()){
            if(r==0 && c==0) return true;
            return false;
        }

        if(moves[i] == 'R') c++;

        else if(moves[i] == 'L') c--;

        else if(moves[i] == 'U') r++;

        else r--;

        return isOrigin(moves,r,c,i+1);
    }
public:
    bool judgeCircle(string moves) {
        int r = 0;
        int c = 0;
        int i = 0;

        return isOrigin(moves,r,c,i);
    }
};