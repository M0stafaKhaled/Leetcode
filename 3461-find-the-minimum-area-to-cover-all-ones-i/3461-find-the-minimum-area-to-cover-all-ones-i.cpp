class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {

        int r1, r2;
        int c1, c2;
        r1 = c1 = INT_MAX;
        r2 = c2 = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {

                    r1 = min(r1, j);
                    c1 = min(c1, i);
                    r2 = max(r2, j);
                    c2 = max(c2, i);
                }
            }
        }
        int w = (r2 - r1) + 1;
        int h = (c2 - c1) + 1;
        cout << w << " " << h << endl;
        cout << r1 << " " << r2 << endl;
        cout << c1 << " " << c2 << endl;
        return h * w;
    }
};