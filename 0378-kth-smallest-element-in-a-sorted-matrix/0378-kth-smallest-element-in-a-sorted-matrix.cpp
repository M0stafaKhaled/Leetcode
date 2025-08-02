class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        using T = array<int, 3>;
        priority_queue<T, vector<T>, greater<T>> pq;

        for (int i = 0; i < matrix.size(); i++) {
            pq.push({matrix[i][0], i, 0});
        }
        int ans = 0;
        while (k > 1 && pq.size()) {
            auto [v, i, j] = pq.top();
            pq.pop();
            j++;

            if (j < matrix.size()) {
                pq.push({matrix[i][j], i, j});
            }
            k--;
        }
        return pq.top()[0];
    }
};