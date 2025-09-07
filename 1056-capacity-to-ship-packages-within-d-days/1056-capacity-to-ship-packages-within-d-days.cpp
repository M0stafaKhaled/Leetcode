class Solution {
public:
    bool solve(vector<int>& weights, int days, int cp) {
        for (int i = 0; i < weights.size(); i++) {
            int cur = cp - weights[i];
            days--;
            if (cur < 0)
                return 0;
            while (i + 1 < weights.size() && cur - weights[i + 1] >= 0) {
                i++;
                cur -= weights[i];
            }
        }

        return days >= 0;
    }
    int shipWithinDays(vector<int>& weights, int days) {

        int st = 1;
        int end = 1e9;
        int ans = 0;
        while (end >= st) {
            int mid = (st + end) / 2;

            if (solve(weights, days, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }

        return ans;
    }
};