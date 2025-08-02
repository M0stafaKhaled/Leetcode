class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {

        long long ans = 0;

        int d = total / cost1;
        int f = 0;
        while (d >= 0) {
            int rem = total - (f * cost1);
            ans += (rem / cost2) + 1;
            f++;
            d--;
        }
        return ans;
    }
};