class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        
        int m = queries.size();

        vector<pair<int,int>> q2(m);

        for(int i=0; i<m; i++){
            q2[i] = {queries[i],i};
        }

        sort(q2.begin(),q2.end());

        sort(logs.begin(),logs.end(),[](vector<int> a,vector<int> b){
            return a[1] < b[1];
        });

        vector<int> ans(m);

        int i = 0;
        int j = 0;

        unordered_map<int,int> mp;

        for(int k=0; k<m; k++){
            int s = q2[k].first - x;
            int e = q2[k].first;

            while(j < logs.size() && logs[j][1] <= e){
                mp[logs[j][0]]++;
                j++;
            }

            while(i < logs.size() && logs[i][1] < s){
                mp[logs[i][0]]--;

                if(mp[logs[i][0]] == 0){
                    mp.erase(logs[i][0]);
                }

                i++;
            }

            int count = mp.size();

            ans[q2[k].second] = n - count;
        }

        return ans;
    }
};