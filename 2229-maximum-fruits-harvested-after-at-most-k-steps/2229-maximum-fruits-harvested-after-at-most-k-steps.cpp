class Solution {
public:
    vector<int> pre;
    int ans = 0;
    int max_f = 0;
    void solve_r(int startPos, int k) {

        int left = 0, right = k;
        if (startPos - k < 0) {
            int temp = abs(startPos - k) / 2;
            left = temp;
            right = startPos;
        }
        int t = startPos - k < 0 ? abs(startPos - k) % 2 : 0;
        while (left <= k) {
            int start = max(startPos - right, 0);
            int end = min(startPos + left, (int)pre.size() - 1);

            int cu = (start > 0 ? pre[end] - pre[start - 1] : pre[end]);
            ans = max(ans, cu);
            right--;
            if (right < 0) {
                right = 0;
                left++;
            } else {
                t++;
                if (t == 2) {
                    t = 0;
                    left++;
                }
            }
        }
    }
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        max_f = fruits[fruits.size() - 1][0];
        int n = max(fruits.back()[0], startPos + k) + 3;
        cout << n << endl;
        pre = vector<int>(n + 1);

        for (int i = 0; i < fruits.size(); i++) {
            pre[fruits[i][0]] = fruits[i][1];
        }

        for (int i = 1; i < n; i++) {
            pre[i] += pre[i - 1];
        }
        int left = k;
        int right = 0;
        int temp = max(0, max_f - startPos);
        if (left + startPos > max_f) {

            cout << temp << endl;
            right = max(0, k - temp) / 2;
            left = temp;
        }
        int t = k + startPos > max_f ? (k - temp) % 2 : 0;
        while (right <= k) {
            int start = max(startPos - right, 0);
            int end = min(startPos + left, n - 1);

            if (start > 0) {
                ans = max(ans, pre[end] - pre[start - 1]);
            } else {
                ans = max(ans, pre[end]);
            }
            //  cout << start << " " << end << " " << ans << endl;
            left--;
            if (left < 0) {
                left = 0;
                right++;
            } else {
                t++;
                if (t == 2) {
                    right++;
                    t = 0;
                }
            }
        }
        solve_r(startPos, k);

        return ans;
    }
};