class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int deficit = 0;
        int balance = 0;
        int start = 0;

        for(int i=0; i<n; i++){
            balance = balance + gas[i] - cost[i];

            if(balance < 0){
                deficit += balance;
                start = i + 1;
                balance = 0;
            }

        }

        if(balance + deficit >= 0){
            return start;
        }

        return -1;
    }
};