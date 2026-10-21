class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int,vector<int>> pq(less<int>(),stones);

        while(pq.size() > 1){
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();

            if(x == y){
                continue;
            }

            int left = y - x;

            pq.push(left);
        }

        if(pq.empty()) return 0;

        return pq.top();
    }
};