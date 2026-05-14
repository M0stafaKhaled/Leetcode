class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int n = right;

        vector<int> pre(100 + 3, 0);

        for (int i = 0; i < ranges.size(); i++) {
            int a = ranges[i][0];
            int b = ranges[i][1];

            pre[a]++;
            pre[b + 1]--;
        }

        for (int i = 1; i <= left; i++) {
            pre[i] += pre[i - 1];
        }
        if (pre[left] == 0)
            return false;

        for (int i = left + 1; i <= right; i++) {
            pre[i] += pre[i - 1];
            if (pre[i] <= 0)
                return false;
        }

        if (right >= 33) {
            cout << pre[33] << endl;
        }

        return 1;
    }
};