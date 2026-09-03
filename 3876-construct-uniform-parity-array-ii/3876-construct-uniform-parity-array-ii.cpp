class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

      int minodd = INT_MAX;

      for(int num : nums1) {
        if(num & 1) {
            minodd = min(minodd, num);
        }
        
      }  

      if(minodd == INT_MAX) return true;

      for(int num : nums1) {

        if(num % 2 == 0 && minodd != INT_MAX && num < minodd){
            return false;
        }
      }

      return true;
    }
};