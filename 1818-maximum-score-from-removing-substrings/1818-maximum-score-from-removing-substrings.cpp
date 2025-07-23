class Solution {
public:
    int ans = 0;
    string solve(string s, string s1, bool y , int d) {
        for (int i = 0; i < s.size(); i++) {
            if (!s1.empty() && ((s1.back() == 'b' && s[i] == 'a' && y) ||
                               (s1.back() == 'a' && s[i] == 'b' && !y))) {
                s1.pop_back();
                ans += d;

            } else {
                s1 += s[i];
            }
        }
        return s1;
    }
    int maximumGain(string s, int x, int y) {

        string s1, s2;
        s1 = "";
        s2 = "";
        if (y >= x) {
            s1 = solve(s, "", true , y);
            solve(s1, "", false, x);
        } else {
            s2 = solve(s, "", false ,x);
            solve(s2, "", true ,y);
        }

        return ans;
    }
};