class Solution {
public:
    bool solve(vector<int>& houses, vector<int>& heaters, int mid) {
        int he = 0;
        int ho = 0;
        while (he < heaters.size()) {
            int start = heaters[he] - mid;
            int end = heaters[he] + mid;
            while (ho < houses.size() && houses[ho] >= start &&
                   houses[ho] <= end) {
                ho++;
            }
            he++;
        }

        return ho == houses.size();
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int start = 0;
        int end = 1e9;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int ans = 0;
        while (end >= start) {
            int mid = (end + start) / 2;
            if (solve(houses, heaters, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }
};