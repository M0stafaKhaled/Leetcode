class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {

        queue<pair<int, int>> q;
        int ans = -1;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }
        int dir[5] = {1, 0, -1, 0, 1};
        while (q.size()) {
            int sz = q.size();
            ans++;
            while (sz--) {
                auto [x, y] = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int dx = dir[i] + x;
                    int dy = dir[i+1] + y;
                    if (dx < 0 || dy < 0 || dx >= grid.size() ||
                        dy >= grid[0].size() || grid[dx][dy] == 1)
                        continue;
                    grid[dx][dy] = 1;
                    q.push({dx, dy});
                }
            }
        }

        if (ans == 0 || ans == -1)
            return -1;

        return ans;
    }
};