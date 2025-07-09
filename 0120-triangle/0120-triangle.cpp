class Solution {
public:
    vector<vector<int>> db;
    int solve(vector<vector<int>>& triangle, int i, int j) {
        if (i == triangle.size())
            return 0;
        if (j >= triangle[i].size())
            return 1e9;
        if (db[i][j] != -1)
            return db[i][j];
        int ans = solve(triangle, i + 1, j) + triangle[i][j];

        ans = min(solve(triangle, i + 1, j + 1) + triangle[i][j], ans);
        db[i][j] = ans;
        return ans;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n - 1].size();
        db = vector<vector<int>>(n,vector<int>(m , -1) );
        return solve(triangle, 0, 0);
    }
};