class Solution {
public:
    long long pow[32];
    const int mod = 1e9 + 7;
    int countPairs(vector<int>& de) {

        pow[0] = 1;
        pow[1] = 2;
        for (int i = 2; i < 32; i++) {
            pow[i] = 2LL * pow[i - 1];
            cout << pow[i] << endl;
        }
        long long ans = 0;

        unordered_set<int> st;
        unordered_map<int, int> map;
        for (int i = 0; i < de.size(); i++) {
            map[de[i]]++;
        }
        for (int i = 0; i < de.size(); i++) {
            map[de[i]]--;
            for (int j = 0; j < 32; j++) {
                long long cur = pow[j] - de[i];
                if (cur < 0)
                    continue;
                if (map[cur]) {
                    ans = (ans + map[cur]) % mod;
                }
            }
        }
        return ans;
    }
};