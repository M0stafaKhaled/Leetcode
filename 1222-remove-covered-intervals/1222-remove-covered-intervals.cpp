class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());
        int ans = 0;
        for (int i = 0; i < intervals.size(); i++) {
            int a = intervals[i][0];
            int b = intervals[i][1];
            while (i + 1 < intervals.size() &&
                   intervals[i][0] == intervals[i + 1][0]) {
                b = max(b, intervals[i + 1][1]);
                i++;
            }
            while (i + 1 < intervals.size() && b >= intervals[i + 1][1])
                i++;
            ans++;
        }
        return ans;
    }
};