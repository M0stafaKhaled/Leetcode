class Solution {
public:
    int dp[500][500];
    int n;
    int solve(vector<int>& arr, int l, int r, int k, int m) {
        if ((r - l) + 1 > k)
            return 0;
        if (r == n)
            return 0;
        if (dp[l][r] != -1)
            return dp[l][r];
        int ans = 0;

        ans = max(m, arr[r]) * ((r - l) + 1);
        // if (r == n - 1) {
        //     cout << ans << endl;
        // }
        ans += solve(arr, r + 1, r + 1, k, 0);
        // if (r == n - 1) {
        //     cout << ans << endl;
        // }
        ans = max(ans, solve(arr, l, r + 1, k, max(arr[r], m)));
        // if (r == n - 1) {
        //     cout << ans << endl;
        // }

        return dp[l][r] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp, -1, sizeof dp);
        n = arr.size();
        arr.push_back(0);

        return solve(arr, 0, 0, k, arr[0]);
    }
};