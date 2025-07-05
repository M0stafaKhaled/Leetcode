class Solution {
public:
    int db[301][301];
    int solve(vector<vector<int>>& matrix, int i, int j) {
        if (i >= matrix.size() || j >= matrix[0].size())
            return 0;
        if (matrix[i][j] == 0)
            return 0;
        if (db[i][j] != -1)
            return db[i][j];
        int ans = 0;
        int down = solve(matrix, i + 1, j);

        int da = solve(matrix, i + 1, j + 1);
        int right = solve(matrix, i, j + 1);

        return db[i][j] = min({right, down, da}) + 1;
    }
    int countSquares(vector<vector<int>>& matrix) {
        int ans = 0;
        memset(db, -1, sizeof(db));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {

                if (matrix[i][j] == 1) {
                    ans += solve(matrix, i, j);
                }
            }
        }

        return ans;
    }
};