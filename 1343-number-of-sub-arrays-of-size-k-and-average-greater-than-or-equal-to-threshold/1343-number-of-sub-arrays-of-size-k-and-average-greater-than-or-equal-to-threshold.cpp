class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {

        int n = arr.size();

        long long sum = 0;

        for(int i = 0; i < k; i++){
            sum += arr[i];
        }

        int cnt = 0;

        if(sum / k >= threshold) cnt++;

        for(int right = k; right < n; right++){

            sum += arr[right];
            sum -= arr[right - k];

            if(sum / k >= threshold){
                cnt++;
            }

        }

        return cnt;
    }
};