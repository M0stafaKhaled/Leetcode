class Solution {
public:
int binom(int n, int k) {
    return 1/((n+1)*std::beta(n-k+1,k+1));
}
    int numWaterBottles(int numBottles, int numExchange) {
        int x = 0;
        int ans = 0;
        while (numBottles) {

            ans += numBottles;
            x += numBottles;
            numBottles = x / numExchange;
            x= x%numExchange;
        }
        return ans;
    }
};