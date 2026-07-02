class Solution {
public:
    int maxrecthistograms(vector<int> & nums) {
        int n = nums.size();
        stack<int> st;
        int maxarea = INT_MIN;

        for(int i = 0; i < n; i++){

            while(!st.empty() && nums[st.top()] > nums[i]){
                int ind = st.top();
                st.pop();

                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxarea = max(maxarea, nums[ind] * (nse - pse - 1));
            }

            st.push(i);
        }


        while(!st.empty()){
            int ind = st.top();
            st.pop();

            int nse = n;
            int pse = st.empty() ? -1 : st.top();

            maxarea = max(maxarea, nums[ind] * (nse - pse - 1));
        }

        return maxarea;

    }
    int maximalRectangle(vector<vector<char>>& matrix) {
    
        if(matrix.empty() || matrix[0].empty()) return 0;

        int m = matrix.size(); //rows
        int n = matrix[0].size(); //cols
        vector<int> height(n, 0);
        int maxarea = 0;

        for(int i = 0; i < m; i++){

            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }

            int area = maxrecthistograms(height);
            maxarea = max(maxarea, area);

        }

        return maxarea;
    }
};