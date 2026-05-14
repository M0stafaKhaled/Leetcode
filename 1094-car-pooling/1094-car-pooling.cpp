class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        vector<int> cap(1001, 0);

        for (int i = 0; i < trips.size(); i++) {

            int a = trips[i][0];
            int b = trips[i][1];
            int c = trips[i][2];

            cap[b] += a;
            cap[c] -= a;
        }

        int cur = 0;
        for (int i = 0; i < 1001; i++) {
            cur += cap[i];

            if (cur > capacity)
                return 0;
        }

        return true;
    }
};