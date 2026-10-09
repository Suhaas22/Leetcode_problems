class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {

        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int n = houses.size();
        int m = heaters.size();

        int maxradius = INT_MIN;

        int i = 0;
        int j = 0;

        while(i < n){

            while((j + 1 < m) && (abs(houses[i] - heaters[j]) >= abs(houses[i] - heaters[j + 1]))){
                j++;
            }

            maxradius = max(maxradius, abs(houses[i] - heaters[j]));

            i++;

        }

        return maxradius;
    }
};