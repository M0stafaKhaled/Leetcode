class Solution {
public:
   bool is_valid(vector<vector<int>>& mat, int i, int j) {
        if (i >= mat.size() || i < 0 || j >= mat[0].size() || j < 0)
            return 0;

        return 1;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size(), 1e9));

        queue<pair<int, int>> q;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dir[5] = {1, 0, -1, 0, 1};
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int ddx = x + dir[i];
                int ddy = y + dir[i + 1];
                if(is_valid(mat , ddx , ddy))
                {
                    if(ans[ddx][ddy] > ans[x][y] +1) 
                    {
                       ans[ddx][ddy] =  ans[x][y] +1 ; 
                       q.push({ddx , ddy}) ; 
                    }
                }
            }
        }

        return ans ; 
    }
};