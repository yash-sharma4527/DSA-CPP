class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        typedef pair<int,int> P;

        auto cmp = [](P a , P b){
            return (a.first*a.first + a.second*a.second) <
                    (b.first*b.first + b.second*b.second); 
        };

        priority_queue<P,vector<P>,decltype(cmp)> pq(cmp);

        for(auto &point : points){
            pq.push({point[0],point[1]});

            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<vector<int>> result;

        while(!pq.empty()){
            result.push_back({pq.top().first,pq.top().second});

            pq.pop();
        }

        return result;
    }
};