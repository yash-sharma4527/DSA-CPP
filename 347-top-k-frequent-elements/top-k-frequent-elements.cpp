class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        typedef pair<int,int> P;

        unordered_map<int,int> mp;

        for(int n : nums){
            mp[n]++;
        }

        auto it = mp.begin();

        priority_queue<P,vector<P>,greater<P>> pq;

        while(it != mp.end()){
            int val = it->first;
            int freq = it->second;

            pq.push({freq,val});

            if(pq.size() > k){
                pq.pop();
            }

            it++;
        }

        vector<int> result;

        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};