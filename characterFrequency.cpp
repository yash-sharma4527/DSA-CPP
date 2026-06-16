#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;

    cout << "Enter the string : ";

    getline(cin,str);

    int hash[256] = {0};

    for(int i=0; i<str.size(); i++){
        hash[str[i]]++;
    }

    char ch;

    cout << "Enter the character : " ;
    cin >> ch;

    cout << ch << "-->" << hash[ch];

    return 0;
}