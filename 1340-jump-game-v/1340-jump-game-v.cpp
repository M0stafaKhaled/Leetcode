class Solution {
public:
    vector<int> dp;
    int solve(vector<int>& arr, int d, int idx) {

        if (dp[idx] != -1)
            return dp[idx];

        dp[idx] = 1;
        // left
        int n = arr.size() - 1;
        for (int i = idx + 1; i <= min(idx + d, n); i++) {
            // if (dp[i] == -1)
            if (arr[i] >= arr[idx])
                break;
            dp[idx] = max(solve(arr, d, i) + 1, dp[idx]);
        }

        for (int i = idx - 1; i >= max(idx - d, 0); i--) {
            //   if (dp[i] == -1)
            if (arr[i] >= arr[idx])
                break;
            dp[idx] = max(solve(arr, d, i) + 1, dp[idx]);
        }

        return dp[idx];
    }
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        dp = vector<int>(n, -1);

        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            ans = max(solve(arr, d, i), ans);
        }

        return ans;
    }
};