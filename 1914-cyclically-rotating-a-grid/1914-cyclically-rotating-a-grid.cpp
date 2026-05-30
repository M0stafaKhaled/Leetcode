class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> ans = grid;

        int layers = min(m, n) / 2;

        for (int layer = 0; layer < layers; layer++) {
            vector<pair<int, int>> cells;

            int top = layer;
            int bottom = m - layer - 1;
            int left = layer;
            int right = n - layer - 1;

            
            for (int col = left; col <= right; col++) {
                cells.push_back({top, col});
            }

           
            for (int row = top + 1; row <= bottom; row++) {
                cells.push_back({row, right});
            }

           
            for (int col = right - 1; col >= left; col--) {
                cells.push_back({bottom, col});
            }

           
            for (int row = bottom - 1; row > top; row--) {
                cells.push_back({row, left});
            }

            int len = cells.size();
            int shift = k % len;

            for (int i = 0; i < len; i++) {
                int newIndex = (i - shift + len) % len;

                int oldRow = cells[i].first;
                int oldCol = cells[i].second;

                int newRow = cells[newIndex].first;
                int newCol = cells[newIndex].second;

                ans[newRow][newCol] = grid[oldRow][oldCol];
            }
        }

        return ans;
    }
};