class Solution {
public:
  vector<vector<int>> db;
    int solve(vector<vector<char>>& matrix, int i, int j) {
        if (i >= matrix.size())
            return 0;
        if (j == matrix[0].size())
            return 0;
        if (matrix[i][j] == '0') {
            return 0;
        }
        if(db[i][j] != -1)  return db[i][j];
        return db[i][j] =  min({solve(matrix, i + 1, j), solve(matrix, i + 1, j + 1),
                    solve(matrix, i, j + 1)}) +
               1;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
       db=   vector<vector<int>>(matrix.size() , vector<int>(matrix[0].size() , -1 )); 
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                int cur = solve(matrix, i, j);
                ans = max(ans,  cur *cur);
            }
        }
        return ans;
    }
};