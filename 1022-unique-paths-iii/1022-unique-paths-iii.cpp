class Solution {
public:
    int dir[5] = {1, 0, -1, 0, 1};
    int db[21][21][41];
    bool vist[20][20];
    int f;
    int solve(vector<vector<int>>& grid, int i, int j, int n) {
        if (i == grid.size() && j == grid[i].size())
            return 0;

        if (grid[i][j] == -1)
            return 0;
       
        if (grid[i][j] == 2) {
            return n == f;
        }
        int ans = 0;

        for (int k = 0; k < 4; k++) {
            int dx = i + dir[k];
            int dy = j + dir[k + 1];
            if (dx >= grid.size() || dx < 0 || dy >= grid[0].size() || dy < 0)
                continue;
            if (grid[dx][dy] == -1)
                continue;
            if (vist[dx][dy])
                continue;
            vist[dx][dy] = true;
            ans = (ans + solve(grid, dx, dy, n + 1));
            vist[dx][dy] = 0;
        }

        return db[i][j][n] = ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {

        memset(db, -1, sizeof db);
        int x = 0;
        int y = 0;
        f = 1;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    vist[i][j] = true;
                    x = i;
                    y = j;
                    f++;
                }
                if (grid[i][j] == 0) {
                    f++;
                }
            }
        }

        return solve(grid, x, y, 1);
    }
};