class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {

        int cur = 0;
        int ans = 0;
        while (numBottles || cur) {
            if(numBottles ==0 && cur <numExchange) break ; 
            if (cur >= numExchange) {
                cur -= numExchange;
                numExchange++;
                numBottles++;
                continue;
            }
            ans += numBottles;
            cur += numBottles;
            numBottles = 0;
        }

        return ans;
    }
};