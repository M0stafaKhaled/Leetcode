class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {

        vector<int> pre(n + 1);

        for (int i = 0; i < bookings.size(); i++) {

            int a = bookings[i][0] - 1;
            int b = bookings[i][1] - 1;
            int c = bookings[i][2];
            pre[a] += c;
            pre[b + 1] -= c;
        }
        vector<int> ans(n);
        int cur = 0;
        for (int i = 0; i < n; i++) {
            cur += pre[i];
            ans[i] = cur;
        }

        return ans;
    }
};