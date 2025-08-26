class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& d) {
        double da = 0;

        for (int i = 0; i < d.size(); i++) {
            int a = d[i][0];
            int b = d[i][1];
            a *= a;
            b *= b;
            double f = sqrt(a + b);
            da = max(da, f);
        }

        int ans = 0;
        for (int i = 0; i < d.size(); i++) {
            int a = d[i][0];
            int b = d[i][1];
            a *= a;
            b *= b;
            double f = sqrt(a + b);
            if (f == da) {
                ans = max(ans, d[i][0] * d[i][1]);
            }
        }

        return ans;
    }
};