class Solution {
public:
    vector<vector<int>> db;
    int solve(vector<vector<int>>& grid, int i, int j) {
        if (grid.size() == i + 1 && grid[0].size() == j + 1)
            return grid[i][j];
        if (i == grid.size())
            return 1e9;
        if (j == grid[0].size())
            return solve(grid, i + 1, j);
        if (db[i][j] != -1)
            return db[i][j];
        int cur = grid[i][j];

        int ans = 0;
        // if (i + 1 < grid.size())
        ans = solve(grid, i + 1, j);
        // if (j + 1 < grid[0].size())
        ans = min(solve(grid, i, j + 1), ans);
        return db[i][j] = ans + cur;
    }
    int minPathSum(vector<vector<int>>& grid) {

        db = vector<vector<int>>(grid.size(), vector<int>(grid[0].size(), -1));

        return solve(grid, 0, 0);
    }
};