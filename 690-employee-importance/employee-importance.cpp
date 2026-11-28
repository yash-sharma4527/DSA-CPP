/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
    int total = 0;

    void dfs(auto &employees,int id,auto &mp){

        total += employees[mp[id]]->importance;

        for(int x : employees[mp[id]]->subordinates){
            dfs(employees,x,mp);
        }

    }

public:
    int getImportance(vector<Employee*> employees, int id) {
        
        unordered_map<int,int> mp;

        int n = employees.size();

        for(int i=0; i<n; i++){
            mp[employees[i]->id] = i;
        }

        dfs(employees,id,mp);

        return total;
    }
};