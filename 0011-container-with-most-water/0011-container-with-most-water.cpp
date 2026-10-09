class Solution {
public:
    int maxArea(vector<int>& height) {

        int n = height.size();

        int maxwater = 0;

        int left = 0;
        int right = n - 1;

        while(left < right){

            int length = min(height[left], height[right]);
            int breadth = right - left;

            maxwater = max(maxwater, length * breadth);

            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }

        return maxwater;
    }

};