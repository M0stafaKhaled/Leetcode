class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {

        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < grid.size(); i++) {
            int x = i;
            int y = 0;
            if (grid[x][y] == 1) {
                grid[x][y] = 2;
                q.push({x, y});
            }
            y = grid[i].size() - 1;
            if (grid[x][y] == 1) {
                grid[x][y] = 2;
                q.push({x, y});
            }
        }

        for (int j = 1; j < grid[0].size() - 1; j++) {
            int x = 0;
            int y = j;
            if (grid[x][y] == 1) {
                grid[x][y] = 2;
                q.push({x, y});
            }
            x = grid.size() - 1;
            if (grid[x][y] == 1) {
                grid[x][y] = 2;
                q.push({x, y});
            }
        }
        int dir[5] = {1, 0, -1, 0, 1};
        while (q.size()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int dx = dir[i] + x;
                int dy = dir[i + 1] + y;
                if (dx < 0 || dx >= n || dy < 0 || dy >= m)
                    continue;
                if (grid[dx][dy] == 1) {
                    grid[dx][dy] = 2;
                    q.push({dx, dy});
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1) {
                    cout << i << " " << j << endl;
                    ans++;
                }
            }
        }

        return ans;
    }
};