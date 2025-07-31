class Solution {
public:
    int solve(int i, vector<bool>& vist, int n) {
        if (n == 0)
            return 1;
        int ans = 0;
        for (int j = 0; j <= 9; j++) {
            if (i == 0 && j == 0)
                continue;
            if (vist[j])
                continue;

            vist[j] = 1;
            ans += solve(i + 1, vist, n - 1);
            vist[j] = 0;
        }
        return ans;
    }
    int countNumbersWithUniqueDigits(int n) {
        // 090

        int ans = 0;
        for (int i = 0; i <=n; i++) {
            vector<bool> vist(9);
            ans += solve(0, vist, i);
        }
        return ans;
    }
};