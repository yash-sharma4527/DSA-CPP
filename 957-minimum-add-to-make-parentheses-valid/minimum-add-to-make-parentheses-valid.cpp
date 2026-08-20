class Solution {
public:
    int minAddToMakeValid(string s) {
        if(s.size() == 0) return 0;

        stack<char> st;

        for(char ch : s){
            if(ch == '('){
                st.push(ch);
            }
            else if(ch == ')' && !st.empty() && st.top()== '('){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }

        return st.size();
    }
};