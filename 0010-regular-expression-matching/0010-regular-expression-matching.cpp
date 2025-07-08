class Solution {
public:
    bool solve(string& s, string& p, int i, int j) {

        if (j == p.size())
            return i == s.size();
        if (i > s.size())
            return 0;
        if (j + 1 < p.size() && p[j + 1] == '*') {
            bool check = solve(s, p, i, j + 2);
            if (((p[j] == s[i] || p[j] == '.')))
                check |= solve(s, p, i + 1, j);
            return check;

        } else {
            if (((p[j] == '.' || p[j] == s[i])))
                return solve(s, p, i + 1, j + 1);
            return false;
        }
    }
    bool isMatch(string s, string p) { return solve(s, p, 0, 0); }
};