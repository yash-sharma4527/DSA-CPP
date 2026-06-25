class Solution {
    bool isEqual(int count1[],int count2[]){
        for(int i=0; i<26; i++){
            if(count1[i]!=count2[i]){
                return 0;
            }
        }
        return 1;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();

        int count1[26] = {0};

        for(int i=0; i<m; i++){
            int index = s1[i] - 'a';
            count1[index]++;
        }

        int count2[26] = {0};

        // for first window
        
        int i = 0;

        while(i<m && i<s2.size()){
            int index = s2[i] - 'a';
            count2[index]++;
            i++;
        }

        if(isEqual(count1,count2)) return 1;

        while(i<s2.size()){
            int index = s2[i] - 'a';
            count2[index]++;
            char oldChar = s2[i-m];
            index = oldChar - 'a';
            count2[index]--;

            if(isEqual(count1,count2)) return 1;
            i++;
        }

        return 0;
    }
};