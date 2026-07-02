class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int largest = INT_MIN;
        stack<int> st;
        int n = heights.size();

        for(int i = 0; i < n; i++){

            while(!st.empty() && heights[st.top()] > heights[i]){
                int el = st.top();
                st.pop();

                int nse = i;
                int pse = st.empty() ? -1 : st.top();

                largest = max(largest, heights[el] * (nse - pse - 1));
            }

            st.push(i);
        }


        while(!st.empty()){
            int ind = st.top();
            st.pop();

            int nse = n;
            int pse = st.empty() ? -1 : st.top();

            largest = max(largest, heights[ind] * (nse - pse - 1));
        }

        return largest;
        
    }
};