class Solution {
    static bool compare(pair<int,int> p1,pair<int,int> p2){
        if(p1.second == p2.second){
            return p1.first > p2.first;
        }

        return p1.second < p2.second ;
    }
public:
    vector<int> frequencySort(vector<int>& nums) {
        
        unordered_map<int,int> mp;

        for(int &x : nums){
            mp[x]++;
        }

        vector<pair<int,int>> vec;

        auto it = mp.begin();
        
        while(it != mp.end()){
            pair<int,int> p = {it->first,it->second};
            vec.push_back(p);
            it++;
        }

        sort(begin(vec),end(vec),compare);

        vector<int> ans;

        for(auto &p : vec){
            for(int i=0; i<p.second; i++){
                ans.push_back(p.first);
            }
        }

        return ans;
    }
};