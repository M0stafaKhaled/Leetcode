class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {

        int n = prices.size();

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int cur = i;

            while (i + 1 < n && prices[i] == prices[i + 1] + 1) {
                i++;
            }
            int d = (i - cur) + 1;
            // cout << d << endl;
            ans += ((d * 1L * (d + 1))) / 2;
        }

        return ans;
    }
};