class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans = 0;

        for(char ch : stones){
            if(jewels.find(ch) != string::npos){
                ans++;
            }
        }

        return ans;
    }
};