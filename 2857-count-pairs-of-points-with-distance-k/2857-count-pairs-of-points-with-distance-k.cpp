class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        // x1 ^ x2 + y1 ^ y2 = k
        //(x1 ^  x2 + y1 ^ y2) -k =0 ;

        // x1 ^ k = x2
        // y1 ^ k = y2 ;
        int ans = 0;
        map<pair<int, int>, int> map1, map2;
        for (int i = 0; i < coordinates.size(); i++) {
            int a = coordinates[i][0];
            int b = coordinates[i][1];

            for (int part = 0; part <= k; part++) {
                int ax = a ^ part;
                int bx = b ^ (k - part);

                auto it = map1.find({ax, bx});

                if (it != map1.end()) {
                    ans += it->second;
                }
            }

            map1[{a, b}]++;
        }

        return ans;
    }
};