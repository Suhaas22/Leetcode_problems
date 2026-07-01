class Solution {
public:
    int trap(vector<int>& height) {
        int lmax = 0;
        int rmax = 0;
        int total = 0;

        int n = height.size();
        int l = 0;
        int r = n - 1;

        while(l < r){
            if(height[l] <= height[r]){
                if(height[l] <= lmax){
                    total += lmax - height[l];
                }
                else{
                    lmax = height[l];
                }

                l++;
            }
            else{
                if(height[r] < rmax){
                    total += rmax - height[r];
                }
                else{
                    rmax = height[r];
                }

                r--;
            }

        }

        return total;
        
    }
};