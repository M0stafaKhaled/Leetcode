class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int valid = 0;
        int minf = INT_MAX;
       
        unordered_map<int, int> map1, map2;
        vector<int> cur;
        for (int i = 0; i < basket2.size(); i++) {
            minf = min({

                minf, basket2[i], basket1[i]});
            map1[basket1[i]]++;
            map2[basket2[i]]++;
        }
        long long ans = 0;
        for (auto& e : map1) {
            if ((map1[e.first] + map2[e.first]) % 2 == 1)
                return -1;

            if (map1[e.first] > map2[e.first]) {

                int d = (map1[e.first] - map2[e.first]) / 2;
                while (d--) {
                    cur.push_back(e.first);
                }
            }
        }

        for (auto& e : map2) {
            if (map1[e.first] < map2[e.first]) {

                int d = (map2[e.first] - map1[e.first]) / 2;
                while (d--) {
                    cur.push_back(e.first);
                }
            }
        }
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        for (int i = 0; i < cur.size(); i++) {

            pq.push(cur[i]);
        }
        int rf = cur.size() / 2;

        while (rf--) {
            long long vb = 1L * 2 * minf;
            ans += min(pq.top(), vb);
            pq.pop();
        }

        return ans;
    }
};