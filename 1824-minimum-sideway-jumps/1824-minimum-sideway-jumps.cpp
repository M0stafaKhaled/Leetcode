class Solution {
public:
    int n;
    int db[3][500001][3];
    int solve(vector<vector<int>>& grid, int x, int y, int state) {
        if (y >= n)
            return 0;
        if (x > 2)
            return 1e9;
        if (x < 0)
            return 1e9;
        if (grid[x][y] == 1)
            return 1e9;

        if (db[x][y][state] != -1)
            return db[x][y][state];
        int ans = 1e9;
        ans = min(solve(grid, x, y + 1, 2), ans);
        if (state != 0) {
            ans = min(ans, solve(grid, x + 1, y, 1) + 1);
            ans = min(ans, solve(grid, x + 2, y, 1) + 1);
        }
        if (state != 1) {
            ans = min(ans, solve(grid, x - 1, y, 0) + 1);
            ans = min(ans, solve(grid, x - 2, y, 0) + 1);
        }
        db[x][y][state] = ans;
        return ans;
    }
    int minSideJumps(vector<int>& obstacles) {
        n = obstacles.size();
        memset(db, -1, sizeof db);
        vector<vector<int>> grid(3, vector<int>(n));
        for (int i = 0; i < n; i++) {
            int y = i;
            int x = obstacles[i];
            if (x == 0)
                continue;
            grid[x - 1][y] = 1;
        }

        return solve(grid, 1, 0, 2);
    }
};