#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> arr = {1,2,3,2,3,1,4,5,7,5,6,8};

    int hash[11] = {0};

    for(int i=0; i<arr.size(); i++){
        hash[arr[i]]++;
    }

    cout << "The frequency array : " << endl;

    for(int i=0; i<11; i++){
        cout << i << "-->" << hash[i] << endl;
    }

    return 0; 
}