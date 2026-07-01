class Solution {
public:
    vector<int> findpse(vector<int> &  nums){
        int n = nums.size();
        vector<int> res(n);
        stack<int> st;

        for(int i = 0; i < n;  i++){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }

            res[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        return res;
    }
        vector<int> findpge(vector<int> &  nums){
        int n = nums.size();
        vector<int> res(n);
        stack<int> st;

        for(int i = 0; i < n;  i++){
            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }

            res[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        return res;
    }
        vector<int> findnge(vector<int> & nums){
        int n = nums.size();
        vector<int> nse(n);
        stack<int> st;

        for(int i = n - 1; i>=0; i--){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }

            nse[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        return nse;
    }
    vector<int> findnse(vector<int> & nums){
        int n = nums.size();
        vector<int> nse(n);
        stack<int> st;

        for(int i = n - 1; i>=0; i--){
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }

            nse[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        return nse;
    }
        long long sumsubarrmax(vector<int> & nums){
        vector<int> nge = findnge(nums);
        vector<int> pge = findpge(nums);
        long long total = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            long long left = i - pge[i];
            long long right = nge[i] - i;

            total += 1LL * left * right * nums[i];
        }

        return total;
    }

    long long sumsubarrmin(vector<int> & nums){
        vector<int> nse = findnse(nums);
        vector<int> pse = findpse(nums);
        long long total = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            long long left = i - pse[i];
            long long right = nse[i] - i;

            total += 1LL * left * right * nums[i];
        }

        return total;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumsubarrmax(nums) - sumsubarrmin(nums);
        
    }
};