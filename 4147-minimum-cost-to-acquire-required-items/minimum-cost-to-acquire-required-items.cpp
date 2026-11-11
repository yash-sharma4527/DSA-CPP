class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans = 0;

        if(costBoth <= cost1 + cost2){
            long long miniNeed = min(need1,need2);

            ans += costBoth*miniNeed;
            need1 -= miniNeed;
            need2 -= miniNeed;
        }

        else{
            long long miniNeed = min(need1,need2);

            ans += cost1*miniNeed + cost2*miniNeed;
            need1 -= miniNeed;
            need2 -= miniNeed;
        }

        if(need1 != 0){
            long long miniCost = min(cost1,costBoth);
            ans += miniCost* need1;
        }

        else{
            long long miniCost = min(cost2,costBoth);
            ans += miniCost*need2;
        }

        return ans;
    }
};