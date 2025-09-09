class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        unordered_map<int, int> map;
        map[0] = 1;
        const int mod = (1e9 + 7);
        for (int i = 2; i <= n; i++) {

            unordered_map<int, int> map2;

            for (auto e : map) {
                if (e.first + 1 >= forget)
                    continue;
                map2[e.first + 1] = e.second;
                if (e.first + 1 >= delay) {
                    map2[0] = (e.second + map2[0]) % mod;
                    //    cout<<"test " << endl ;
                }
                // cout << e.first << " " << e.second << endl;
            }

            map = map2;
            // cout << "N: " << i << endl;
            // for (auto e : map) {
            //     cout << e.first << " " << e.second << endl;
            // }
            //   break ;
        }
        long long ans = 0;

        for (auto e : map) {

            ans = (ans + e.second) % mod;
        }
        return ans;
    }
};