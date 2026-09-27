class Solution {
public:
    string reverseParentheses(string s) {
        string ans;

        stack<int> st;

        for(int i=0; i<s.length(); i++){
            if(s[i] == '('){
                st.push(ans.size());
            }

            else if(s[i] == ')'){
                int n = st.top();
                st.pop();

                reverse(ans.begin()+n,ans.end());
            }

            else{
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};