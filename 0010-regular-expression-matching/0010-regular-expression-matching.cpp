class Solution {
public:
    bool solve(string& s, string& p, int i, int j) {
        
        if (j == p.size())
            return i == s.size();

        if (j + 1 < p.size() && p[j + 1] == '*') {

            return solve(s, p, i, j + 2) ||
                    (i<s.size() && (p[j] == s[i] || p[j] == '.')) && solve(s, p, i + 1, j)  ;

        } else {
            return   (i<s.size() && (p[j] == '.' || p[j] == s[i])) && solve(s, p, i + 1, j + 1) ;
        }

        
    }
    bool isMatch(string s, string p) { return solve(s, p, 0, 0); }
};