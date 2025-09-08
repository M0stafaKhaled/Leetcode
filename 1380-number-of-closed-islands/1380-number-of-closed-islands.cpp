class Solution {
public:
    int dir[5] = {1, 0, -1, 0, 1};

    // top down left right
    int dfs(vector<vector<int>>& grid, int x, int y) {

        grid[x][y] = 2;
        int cur = 0;
        for (int i = 0; i < 4; i++) {
            int dx = x + dir[i];
            int dy = y + dir[i + 1];

            if (dx < 0 || dy < 0 || dx >= grid.size() || dy >= grid[0].size()) {
                grid[x][y] = 3;
                continue ; 
            }
            if (grid[dx][dy] == 3 || grid[dx][dy] == 2) {
                cur += grid[dx][dy] == 2;
                continue;
            }

            if (grid[dx][dy] == 1) {
                cur++;
            }
            if (grid[dx][dy] == 0) {
                if (dfs(grid, dx, dy) == 4)
                    cur++;
            }
        }

        return cur;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 0) {
                    if (dfs(grid, i, j) == 4)
                        ans++;
                }
            }
        }
        return ans;
    }
};