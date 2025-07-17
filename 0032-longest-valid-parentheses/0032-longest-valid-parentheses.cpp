class Solution {
public:
    int db[30001];
    int solve(string& s, int i) {
        if (i >= s.size())
            return 0;

        // leave
        int ans = 0;
        if (db[i] != -1)
            return db[i];
        if (s[i] == ')')
            return 0;
        ans = 0;
        int start = 1;
        int end = 0;

        for (int j = i + 1; j < s.size(); j++) {
            if (s[j] == '(') {
                start++;

            } else {
                if (start == 0) {
                    return db[i] = ans;
                }

                start--;
                end++;
            }
            if (start == 0) {
                ans = max(ans, (j - i) + 1);
            }
        }

        return db[i] = ans;
    }
    int longestValidParentheses(string s) {
        memset(db, -1, sizeof db);
        //  cout<<s.size() <<endl ;
        int i = 0;
        while (i < s.size() && s[i] == ')')
            i++;
        int ans = 0;
        for (; i < s.size(); i++) {
            if (ans >= s.size() - i)
                return ans;
            ans = max(solve(s, i), ans);
        }
        return ans;
    }
};