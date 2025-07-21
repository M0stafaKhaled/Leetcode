class Solution {
public:
    int db[2000][2000] ; 
    bool solve(string& s, string& p, int i, int j) {
        if (j == p.size())
            return i == s.size() && j == p.size();

        if(db[i][j] != -1) return db[i][j] ; 
        if (i<s.size() &&s[i] == p[j] || p[j] == '?') {
             return db[i][j] = solve(s, p, i + 1, j + 1);
        }
        if (p[j] == '*') {
           return  db[i][j] =  (i<s.size() && solve(s, p, i + 1, j + 1) ) ||
                         (i<s.size()  && solve(s, p, i + 1, j)) || solve(s, p, i , j+1);
        }

        // if(s[i] =='*')

        return db[i][j] = 0 ;
    }
    bool isMatch(string s, string p) {
        memset(db , -1 ,  sizeof db) ; 

        return solve(s , p , 0 , 0);
     }
};