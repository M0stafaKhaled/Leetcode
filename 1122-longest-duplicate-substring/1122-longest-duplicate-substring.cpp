class Solution {
public:
    const int PRIME = 199;
    const int MOD = 1e9 + 7;

    string solve(string& s, int len) {

        long long hash = 0;
        unordered_set<long long> seen;
        long long power = 1;

        for (int i = 0; i < len; i++) {
            hash = (hash * PRIME + s[i]) % MOD;
            if (i != len - 1)
                power = (power * PRIME) % MOD;
        }

        seen.insert(hash);

        for (int i = len; i < s.size(); i++) {

            hash = (hash - s[i - len] * power % MOD + MOD) % MOD;
            hash = (hash * PRIME + s[i]) % MOD;

            if (seen.count(hash)) {
                string candidate = s.substr(i - len + 1, len);
                for (int j = 0; j <= i - len; j++) {
                    if (s.substr(j, len) == candidate) {
                        return candidate;
                    }
                }
            }
            seen.insert(hash);
        }

        return "";
    }

    string longestDupSubstring(string s) {

        int start = 1;
        int end = s.size() - 1;
        string ans = "";
        while (end >= start) {
            int mid = (end + start) / 2;
            //  cout << mid << endl;
            string cur = solve(s, mid);
            if (cur.size()) {
                if (ans.size() < cur.size())
                    ans = cur;
                start = mid + 1;

            } else
                end = mid - 1;
        }
        return ans;
    }
};