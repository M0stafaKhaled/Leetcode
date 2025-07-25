class Solution {
public:
    vector<int> ans;
    int count = 0;
    int t = 0;
    const int vist = 200;
    void right(vector<vector<int>>& matrix, int i, int j) {
        if (ans.size() == t)
            return;
        if (j == matrix[0].size() || matrix[i][j] == vist) {
            if (i + 1 < matrix.size())
                down(matrix, i + 1, j - 1);
            return;
        }

        ans.push_back(matrix[i][j]);
        matrix[i][j] = vist;
        count++;
        right(matrix, i, j + 1);
    }

    void down(vector<vector<int>>& matrix, int i, int j) {
        if (ans.size() == t)
            return;
        if (i == matrix.size() || matrix[i][j] == vist) {
            if (j - 1 >= 0)
                left(matrix, i - 1, j - 1);
            return;
        }

        ans.push_back(matrix[i][j]);
        matrix[i][j] = vist;
        count++;
        down(matrix, i + 1, j);
    }

    void left(vector<vector<int>>& matrix, int i, int j) {
        if (ans.size() == t)
            return;
        if (j == -1 || matrix[i][j] == vist) {
            if (i - 1 >= 0)
                up(matrix, i - 1, j + 1);
            return;
        }

        ans.push_back(matrix[i][j]);
        matrix[i][j] = vist;
        count++;
        left(matrix, i, j - 1);
    }

    void up(vector<vector<int>>& matrix, int i, int j) {
        cout << i << j << endl;
        if (ans.size() == t)
            return;
        if (i == -1 || matrix[i][j] == vist) {
            right(matrix, i + 1, j + 1);
            return;
        }

        ans.push_back(matrix[i][j]);
        matrix[i][j] = vist;
        count++;
        up(matrix, i - 1, j);
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        t = (n * m);
        right(matrix, 0, 0);
        return ans;
    }
};