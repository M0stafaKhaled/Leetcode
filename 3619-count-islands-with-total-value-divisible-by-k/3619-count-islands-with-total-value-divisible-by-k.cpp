class Solution {
public:
    int dir[5] = {1, 0, -1, 0, 1};
    int d = 0;
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (grid[i][j] == 0)
            return 0;
        int ans = grid[i][j];
        grid[i][j] = 0;
        for (int k = 0; k < 4; k++) {
            int dx = dir[k] + i;
            int dy = dir[k + 1] + j;

            if (dx >= 0 && dy >= 0 && dx < grid.size() && dy < grid[0].size() &&
                grid[dx][dy] != 0) {
                int cur = dfs(grid, dx, dy);
                if (cur == 0)
                    continue;
                ans += cur % d;
            }
        }
        return ans;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int ans = 0;
        d = k;
        for (int i = 0; i < grid.size(); i++) {

            for (int j = 0; j < grid[i].size(); j++) {
                int cur = dfs(grid, i, j);
                if (cur != 0 && cur % k == 0)
                    ans++;
            }
        }
        return ans;
    }
};