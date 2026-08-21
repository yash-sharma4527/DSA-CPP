class Solution {
    vector<int> nextSmallerElement(vector<int>& arr){
        int n = arr.size();

        vector<int> ans(n);
        stack<int> st;

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = n;
            }
            else{
                ans[i] = st.top();
            }
            st.push(i);
        }

        return ans;
    }
    vector<int> previousSmallerElement(vector<int>& arr){
        int n = arr.size();

        vector<int> ans(n);
        stack<int> st;

        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = -1;
            }
            else{
                ans[i] = st.top();
            }
            st.push(i);
        }

        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse = nextSmallerElement(heights);
        vector<int> pse = previousSmallerElement(heights);

        int maxArea = 0;

        for(int i=0; i<heights.size(); i++){
            int width = nse[i] - pse[i] -1;
            int area = heights[i]*width;

            maxArea = max(maxArea,area);
        }

        return maxArea;
    }
};