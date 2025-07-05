class Solution {
public:
    int db[601][101][101];
    int solve(vector<string>& strs, int m, int n, int idx) {
        if (m < 0 || n < 0)
            return -1e9;
        if (idx == strs.size())
            return 0;
        //  if(m==0 && n==0) return 1 ;

        if (db[idx][m][n] != -1)
            return db[idx][m][n];
        int d = 0;
        int r = 0;
        int ans = solve(strs, m, n, idx + 1);
        for (int i = 0; i < strs[idx].size(); i++) {
            if (strs[idx][i] == '1')
                d++;
            if (strs[idx][i] == '0')
                r++;
        }
        if (d <= n && r <= m)
            ans = max(ans, solve(strs, m - r, n - d, idx + 1) + 1);
        return db[idx][m][n] = ans;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(db, -1, sizeof(db)); 

        return solve(strs, m, n, 0);
    }
};