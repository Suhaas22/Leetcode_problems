class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {

        int n = heaters.size();
        int m = houses.size();

        int maxradius = INT_MIN;

        for(int i = 0; i < m; i++){

            int minradius = INT_MAX;

            for(int j = 0; j < n; j++){

                minradius = min(minradius, abs(houses[i] - heaters[j]));
            }

            maxradius = max(maxradius, minradius);
        }

    
        return maxradius;
    }
};