class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(string s : tokens){
            if( s == "+"){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int ans = a+b;
                st.push(ans);
            }
            else if( s == "-"){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int ans = a-b;
                st.push(ans);
            }
            else if( s == "*"){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int ans = a*b;
                st.push(ans);
            }
            else if( s == "/"){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int ans = a/b;
                st.push(ans);
            }
            else{
                st.push(stoi(s));
            }
        }

        return st.top();
    }
};