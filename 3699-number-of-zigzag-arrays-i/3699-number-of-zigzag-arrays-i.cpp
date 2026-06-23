class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MOD = 1e9 + 7;

        vector<int> sornavetic = {n, l, r};

        int m = r - l + 1;

        vector<int> dp(m, 1);

        for (int pos = 1; pos < n; pos++) {
            long long sum = 0;

            if (pos % 2 == 1) {

                for (int v = 0; v < m; v++) {
                    int old = dp[v];
                    dp[v] = sum;
                    sum = (sum + old) % MOD;
                }
            } else {

                for (int v = m - 1; v >= 0; v--) {
                    int old = dp[v];
                    dp[v] = sum;
                    sum = (sum + old) % MOD;
                }
            }
        }

        long long ans = 0;
        for (int x : dp) {
            ans = (ans + x) % MOD;
        }

        return ans * 2 % MOD;
    }
};