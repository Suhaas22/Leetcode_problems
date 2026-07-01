class Solution {
public:
    vector<int> findnse(vector<int> & arr){
        int n = arr.size();
        stack<int> st;
        vector<int> nse(n);

        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }

            nse[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        return nse;
    }

    vector<int> findpse(vector<int> & arr){
        int n = arr.size();
        stack<int> st;
        vector<int> res(n);

        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }

            res[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        return res;
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = findnse(arr);
        vector<int> pse = findpse(arr);
        long long total = 0;
        int n = arr.size();
        int mod = 1e9 + 7;

        for(int i = 0; i < n; i++){
            int left = i - pse[i];
            int right = nse[i] - i;

            total += (left * right * 1LL * arr[i]) % mod;
            total %= mod;
        }

        return total;
    }
};