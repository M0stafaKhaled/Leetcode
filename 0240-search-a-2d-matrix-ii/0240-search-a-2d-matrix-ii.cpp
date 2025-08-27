class Solution {
public:
    bool find(vector<int>& arr, int t) {
        int start = 0;
        int end = arr.size() - 1;
        while (end >= start) {
            int mid = (end + start) / 2;
            if (arr[mid] == t)
                return 1;
            if (arr[mid] > t) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return 0;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        for (int i = 0; i < matrix.size(); i++) {
            if (find(matrix[i], target))
                return 1;
            if (matrix[i][0] > target)
                return 0;
        }

        return 0;
    }
};