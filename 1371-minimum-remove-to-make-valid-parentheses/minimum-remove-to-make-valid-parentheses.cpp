class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st;
        string ans = "";

        // First pass: remove invalid ')'
        for(char ch : s) {
            if(ch == '(') {
                st.push(ch);
                ans.push_back(ch);
            }
            else if(ch == ')') {
                if(!st.empty()) {
                    ans.push_back(ch);
                    st.pop();
                }
            }
            else {
                ans.push_back(ch);
            }
        }

        // Second pass: remove extra '('
        string result = "";

        for(int i = ans.size() - 1; i >= 0; i--) {
            if(ans[i] == '(' && !st.empty()) {
                st.pop();
                continue;
            }

            result.push_back(ans[i]);
        }

        reverse(result.begin(), result.end());

        return result;
    }
};