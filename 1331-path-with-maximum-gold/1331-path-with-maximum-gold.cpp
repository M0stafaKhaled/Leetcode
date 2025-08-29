class Solution {
public:
    int dir[5] = {1, 0, -1, 0, 1};
    int dfs(int i, int j, vector<vector<int>>& grid,
            vector<vector<int>>& visted) {
        visted[i][j] = 2;
        int cur = 0;
        for (int k = 0; k < 4; k++) {
            int dx = dir[k] + i;
            int dy = dir[k + 1] + j;
            if (dx < 0 || dy < 0 || dx >= grid.size() || dy >= grid[0].size())
                continue;
            if (grid[dx][dy] == 0)
                continue;
            if (visted[dx][dy] != 2) {
                //  cout << dx << dy << endl;

                cur = max(dfs(dx, dy, grid, visted), cur);
            }
        }

        visted[i][j] = 1;
        return cur + grid[i][j];
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] > 0) {
                    vector<vector<int>> visted(grid.size(),
                                               vector<int>(grid[0].size()));

                    ans = max(ans, dfs(i, j, grid, visted));
                  
                }
            }
        }

        return ans;
    }
};