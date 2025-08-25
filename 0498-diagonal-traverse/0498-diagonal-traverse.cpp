class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {

        vector<int> ans;
        set<pair<int, int>> st;
        vector<vector<bool>> dir(mat.size(), vector<bool>(mat[0].size()));
        bool cur = true;
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                map[i + j].push_back(mat[i][j]);
            }
        }

        for (int i = 0; i < mat.size() * mat[0].size(); i++) {
            if (i % 2 == 1) {
                for (int j = 0; j < map[i].size(); j++) {
                    ans.push_back(map[i][j]);
                }
            } else {
                for (int j = map[i].size() - 1; j >= 0; j--) {
                    ans.push_back(map[i][j]);
                }
            }
        }

        return ans;
    }
};