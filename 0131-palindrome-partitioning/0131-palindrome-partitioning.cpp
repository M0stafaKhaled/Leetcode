class Solution {
public:
    vector<vector<string>> ans;
    vector<string> cur;
    bool is_valid(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return 0;
                l++; r--;
        }

        return 1;
    }
    void solve(string& s, int l, int r) {
        if (l == s.size()) {
            ans.push_back(cur);
            return;
        }
       if(l>s.size()) return ;

        string d = "";
        for (int i = l; i < s.size(); i++) {
            d += s[i];
            if (is_valid(s, l, i)) {
                cout<<d<<endl ; 
                cur.push_back(d);
                solve(s, i+1,r);
                cur.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {

        solve(s, 0, 0);

        return ans;
    }
};