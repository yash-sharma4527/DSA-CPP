class Solution {
public:
    string frequencySort(string s) {
        int arr[256] = {0};

        for(char ch : s){
            arr[ch]++;
        }

        sort(s.begin(),s.end(),[&](char a,char b){
            if(arr[a] == arr[b]){
                return a > b;
            }
            return arr[a] > arr[b];
        });

        return s;
    }
};