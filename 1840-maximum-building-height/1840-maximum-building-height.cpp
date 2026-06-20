class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {

        restrictions.push_back({1, 0});
        bool hasN = false;
        for (auto& r : restrictions) {
            if (r[0] == n) {
                hasN = true;
                break;
            }
        }

        if (!hasN) {
            restrictions.push_back({n, n - 1});
        }

        sort(restrictions.begin(), restrictions.end());

        int m = restrictions.size();
        for (int i = 1; i < m; i++) {
            int dist = restrictions[i][0] - restrictions[i - 1][0];
            restrictions[i][1] =
                min(restrictions[i][1], restrictions[i - 1][1] + dist);
        }

        for (int i = m - 2; i >= 0; i--) {
            int dist = restrictions[i + 1][0] - restrictions[i][0];
            restrictions[i][1] =
                min(restrictions[i][1], restrictions[i + 1][1] + dist);
        }

        int ans = 0;
        for (int i = 1; i < m; i++) {
            int idA = restrictions[i - 1][0];
            int hA = restrictions[i - 1][1];

            int idB = restrictions[i][0];
            int hB = restrictions[i][1];

            int dist = idB - idA;

            int remaining = dist - abs(hA - hB);

            int peak = max(hA, hB) + remaining / 2;

            ans = max(ans, peak);
        }

        return ans;
    }
};