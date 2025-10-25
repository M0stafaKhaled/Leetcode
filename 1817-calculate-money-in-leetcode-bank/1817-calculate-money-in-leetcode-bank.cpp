class Solution {
public:
    int totalMoney(int n) {
        int m = n / 7;
        int d = n % 7;
        int ans = 0;

        int mr = 28;
        for (int i = 1; i <= m; i++) {
            ans += mr;
            mr += 7;
        }
        for (int i = 1; i <= d; i++) {
            ans += i + m;
        }

        return ans;
    }
};