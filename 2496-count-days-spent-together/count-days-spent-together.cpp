class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        
        int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

        int reachAliceMonths = stoi(arriveAlice.substr(0,2));
        int reachAliceDays = stoi(arriveAlice.substr(3));
        int reachBobMonths = stoi(arriveBob.substr(0,2));
        int reachBobDays = stoi(arriveBob.substr(3));
        
        int goneAliceMonths = stoi(leaveAlice.substr(0,2));
        int goneAliceDays = stoi(leaveAlice.substr(3));
        int goneBobMonths = stoi(leaveBob.substr(0,2));
        int goneBobDays = stoi(leaveBob.substr(3));

        int reachAlice = 0;

        for(int i=0; i<reachAliceMonths-1; i++){
            reachAlice += days[i];
        }

        reachAlice += reachAliceDays;

        int reachBob = 0;

        for(int i=0; i<reachBobMonths-1; i++){
            reachBob += days[i];
        }

        reachBob += reachBobDays;

        int goneAlice = 0;

        for(int i=0; i<goneAliceMonths-1; i++){
            goneAlice += days[i];
        }

        goneAlice += goneAliceDays;

        int goneBob = 0;

        for(int i=0; i<goneBobMonths-1; i++){
            goneBob += days[i]; 
        }

        goneBob += goneBobDays;

        int reach = max(reachAlice,reachBob);
        int gone = min(goneBob,goneAlice);

        return max(0,gone-reach+1);
    }
};