class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        unordered_set<int> seen;

        for(int right = 0; right < nums.size(); right++){

            if(seen.find(nums[right]) != seen.end()) return true;

            seen.insert(nums[right]);

            if(seen.size() > k){
                seen.erase(nums[right - k]);
            }
            
        }

        return false;
    }
};