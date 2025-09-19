class Solution {
public:
    bool solve(int i, int j, vector<vector<int>>& matrix) {
        while (i + 1 < matrix.size() && j + 1 < matrix[0].size()) {

            if (matrix[i + 1][j + 1] != matrix[i][j])
                return 0;
            i++, j++;
        }

        return 1;
    }
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {

        int i = 0;
        int j = 0;

        for (; j < matrix[0].size(); j++) {

            if (!solve(0, j, matrix))
                return 0;
        }

        j = 0;
        i = 1;
        for (; i < matrix.size(); i++) {

            if (!solve(i, j, matrix))
                return 0;
        }

        return 1;
    }
};