class Solution {
public:
    int solve(int mid, vector<int>& price) {
        int last = price[0];
        int ans = 1;
        for (int i = 1; i < price.size(); i++) {
            if (price[i] - last >= mid) {
                ans++;
                last = price[i];
            }
        }
        return ans;
    }
    int maximumTastiness(vector<int>& price, int k) {

        sort(price.begin(), price.end());
        int start = 0;
        int end = price[price.size() - 1] - price[0];
        int ans = 0;
        while (end >= start) {
            int mid = (start + end) / 2;
            if (solve(mid, price) >= k) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }
};