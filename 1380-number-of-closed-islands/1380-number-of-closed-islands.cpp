class Solution {
public:
    int dir[5] = {1, 0, -1, 0, 1};

    // top down left right
    int dfs(vector<vector<int>>& grid, vector<bool>& ans,
            set<pair<int, int>>& st, int x, int y) {

        grid[x][y] = 2;
        int cur = 0;
        for (int i = 0; i < 4; i++) {
            int dx = x + dir[i];
            int dy = y + dir[i + 1];

            if (dx < 0 || dy < 0 || dx >= grid.size() || dy >= grid[0].size()) {
                grid[x][y] = 3;
                return 0;
            }
            if (grid[dx][dy] == 3) {

                continue;
            }
            if (grid[dx][dy] == 2) {
                cur++;
                continue;
            }

            if (grid[dx][dy] == 1) {
                cur++;
            }
            if (grid[dx][dy] == 0) {
                int r = dfs(grid, ans, st, dx, dy);
                if (r == 4)
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
                    vector<bool> tr(4, 0);
                    set<pair<int, int>> st;
                    int ends = dfs(grid, tr, st, i, j);

                    if (ends == 4)
                        ans++;
                    //  ans += cur;
                }
            }
        }
        return ans;
    }
};