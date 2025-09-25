class Solution {
public:
   
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n == 0)
            return 0;

        vector<vector<long long>> dp =
            vector<vector<long long>>(n, vector<long long>(n, 0));

        for (int j = 0; j < triangle[n - 1].size(); j++) {
            dp[n - 1][j] = triangle[n - 1][j];
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
            }
        }

        return dp[0][0];
    }
};