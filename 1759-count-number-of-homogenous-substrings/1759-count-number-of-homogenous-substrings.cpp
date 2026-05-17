class Solution {
public:
    const int mod = 1e9 + 7;
    int countHomogenous(string s) {
        long long  ans = 0;

        for (int i = 0; i < s.size(); i++) {
            int cur = i;
            ans++;
            while (i + 1 < s.size() && s[i] == s[i + 1]) {
                ans += (((i + 1) - cur) + 1) % mod;
                i++;
            }
        }

        return ans % mod;
    }
};