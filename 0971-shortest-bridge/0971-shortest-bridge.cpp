class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        vector<vector<int>> costs(grid.size(),
                                  vector<int>(grid[0].size(), 1e9));

        for (int i = 0; i < grid.size(); i++) {
            bool f = false;
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    costs[i][j] = 0;
                    q.push({i, j});
                    f = true;
                    break;
                }
            }
            if (f)
                break;
        }
        int dir[5] = {1, 0, -1, 0, 1};
        while (q.size()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int dx = dir[i] + x;
                int dy = dir[i + 1] + y;
                if (dx < 0 || dx >= grid.size() || dy >= grid[0].size() ||
                    dy < 0)
                    continue;
               
                if (costs[dx][dy] > costs[x][y] + (grid[dx][dy] == 0)) {
                    costs[dx][dy] = costs[x][y] + (grid[dx][dy] == 0);
                    q.push({dx, dy});
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    ans = max(ans, costs[i][j]);
                }
            }
        }

        return ans;
    }
};