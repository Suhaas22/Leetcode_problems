class Solution {
public:
    int passThePillow(int n, int time) {

        int moves = time % (2 * (n - 1));

        if(moves <= n - 1){
            return moves + 1;
        }

        return n - (moves - (n - 1));
    }
};