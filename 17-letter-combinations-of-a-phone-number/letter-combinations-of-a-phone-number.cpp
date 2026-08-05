class Solution {
    void combinations(string digits,vector<string> letters,int idx,string str,vector<string> &ans){
        if(idx >= digits.size()){
            ans.push_back(str);
            return;
        }

        int num = digits[idx] - '0';
        string value = letters[num];

        for(int j=0; j<value.size(); j++){
            str.push_back(value[j]);
            combinations(digits,letters,idx+1,str,ans);
            str.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> letters = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        vector<string> ans;

        string str = "";

        int i=0;

        combinations(digits,letters,i,str,ans);

        return ans;
    }
};