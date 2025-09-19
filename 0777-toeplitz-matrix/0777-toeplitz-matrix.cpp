class Solution {
public:
    bool solve(int i, int j, vector<vector<int>>& matrix) {
        while (i + 1 < matrix.size() && j + 1 < matrix[0].size()) {
            cout << i + 1 << " " << j + 1 << " " << matrix[i + 1][j + 1]
                 << endl;
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
            cout << i << " " << j << " " << matrix[i][j] << endl;
            if (!solve(0, j, matrix))
                return 0;
            cout << "test" << endl;
        }
        cout<<endl << endl ;
        j =0 ;  
        for (; i < matrix.size(); i++) {
           cout<< i << " " << j << " " << matrix[i][j] << endl;
            if (!solve(i, j, matrix))
                return 0;
            cout << "test" << endl;
        }

        return 1;
    }
};