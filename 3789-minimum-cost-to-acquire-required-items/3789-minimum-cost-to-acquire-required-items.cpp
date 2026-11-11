class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {

        if(need1 == 0 && need2 == 0) return 0;

        long long commoncost = 1LL * min(need1, need2) * min(cost1 + cost2, costBoth);

        if(need1 > need2){
            commoncost += 1LL * (need1 - need2) * min(costBoth, cost1);
        }
        else if(need2 > need1){
            commoncost += 1LL * (need2 - need1) * min(costBoth, cost2);
        }

        return commoncost;
        
    }
};