class Solution {
public:
    string smallestPalindrome(string s) {
        int mid = s.size()/2;
        int n = s.size();

        sort(s.begin(),s.begin()+mid);

        for(int i=0; i<mid; i++){
            s[n-1-i] = s[i];
        }

        return s;
    }
};