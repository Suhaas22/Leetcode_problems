class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        stack<int> st;
        vector<int> ans;
        int n = nums.size();

        for(int i = 0; i < n; i++){

            //removing elements that are outside window
            while(!dq.empty() && dq.front() <= i - k){
                dq.pop_front();
            }

            //removing smaller elements
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }

            dq.push_back(i);

            if(i >= k - 1){
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
        
    }
};