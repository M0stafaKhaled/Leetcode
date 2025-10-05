class Solution {
public:
    int dir[5] = {1, 0, -1, 0, 1};
    void solve1(vector<vector<int>>& grid, vector<vector<int>>& heights,
                vector<vector<bool>>& vist) {
        queue<pair<int, int>> q;
        for (int j = 0; j < heights[0].size(); j++) {
            grid[0][j] = 1;
            vist[0][j] = true;
            q.push({0, j});
        }

        for (int j = 0; j < heights.size(); j++) {

            grid[j][0] = 1;
            vist[j][0] = true;
            q.push({j, 0});
        }

        while (q.size()) {
            auto [x, y] = q.front();
            q.pop();
            // if (vist[x][y])
            //     continue;
            vist[x][y] = 1;
            for (int i = 0; i < 4; i++) {
                int dx = dir[i] + x;
                int dy = dir[i + 1] + y;

                if (dx < 0 || dx >= heights.size() || dy < 0 ||
                    dy >= heights[0].size())
                    continue;

                if (heights[dx][dy] < heights[x][y])
                    continue;
                if (vist[dx][dy])
                    continue;
                vist[dx][dy] = 1;
                // cout << dx << " " << dy << endl;
                grid[dx][dy] += 1;
                q.push({dx, dy});
            }
        }
    }

    void solve2(vector<vector<int>>& grid, vector<vector<int>>& heights,
                vector<vector<bool>>& vist) {
        queue<pair<int, int>> q;
        for (int j = 0; j < heights[0].size(); j++) {
            grid[heights.size() - 1][j] += 2;
            q.push({heights.size() - 1, j});
            vist[heights.size() - 1][j] = true;
        }

        for (int j = 0; j < heights.size() - 1; j++) {
            grid[j][heights[0].size() - 1] += 2;
            q.push({j, heights[0].size() - 1});
            vist[j][heights[0].size() - 1] = true;
        }

        while (q.size()) {
            auto [x, y] = q.front();
            q.pop();
            //  if(vist[x][y]) continue ;
            vist[x][y] = true;
            for (int i = 0; i < 4; i++) {
                int dx = dir[i] + x;
                int dy = dir[i + 1] + y;

                if (dx < 0 || dx >= heights.size() || dy < 0 ||
                    dy >= heights[0].size())
                    continue;

                if (heights[dx][dy] < heights[x][y])
                    continue;
                if (vist[dx][dy])
                    continue;

                vist[dx][dy] = 1;
                //  cout<<dx << " " << dy <<endl ;
                grid[dx][dy] += 2;
                q.push({dx, dy});
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> grid(heights.size(),
                                 vector<int>(heights[0].size(), 0));

        vector<vector<bool>> vist(heights.size(),
                                  vector<bool>(heights[0].size()));
        solve1(grid, heights, vist);
        vist = vector<vector<bool>>(heights.size(),
                                    vector<bool>(heights[0].size()));
        solve2(grid, heights, vist);
        vector<vector<int>> ans;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {

                cout << grid[i][j] << " ";
                if (grid[i][j] == 3) {
                    ans.push_back({i, j});
                }
            }
            cout << endl;
        }

        return ans;
    }
};