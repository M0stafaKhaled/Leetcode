class Solution {
public:
    vector<int> db;
    int solve(string& s, int idx) {
        if (idx > s.size())
            return 0;
        if (idx == s.size())
            return 1;
        if (s[idx] == '0')
            return 0;

        if (db[idx] != -1)
            return db[idx];
        int ans = 0;
        if (idx + 1 < s.size()) {
            int first = s[idx] - '0';
            int second = s[idx + 1] - '0';
            first *= 10;
            first += second;
            if (first <= 26) {
                ans += solve(s, idx + 2);
            }
        }

        ans += solve(s, idx + 1);

        return db[idx] = ans;
    }
    int numDecodings(string s) {
        db = vector<int>(s.size(), -1);
        int ans = solve(s, 0);
        bool check = true;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                check = false;
                if (i - 1 >= 0 && s[i - 1] != '0')
                    continue;
                return 0;
            }
        }
        return ans;
    }
};