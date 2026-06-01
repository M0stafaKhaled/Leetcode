class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
    
        int ans = 0;
        map<pair<int, int>, int> map1;
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