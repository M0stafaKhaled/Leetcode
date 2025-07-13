class Solution {
public:
   vector<int> db;
    bool is_valid(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return 0;
            l++;
            r--;
        }

        return 1;
    }
   
    int solve(string& s, int l) {
        if (l == s.size() -1 ) {
            return 0;
        }
        if(db[l] != -1) return db[l] ;
        int ans = s.size() - 1;
        for (int i = l; i < s.size(); i++) {
            bool  check  = is_valid(s, l, i);
            if(check && i+1 == s.size()) 
            {
                db[l] = 0 ;  
                return 0;   
            }
            if (check) {

                ans = min(solve(s, i + 1)+1  , ans);
            }
        }
        return db[l] =  ans;
    }
    int minCut(string s) {
     
        db = vector<int>(s.size() , -1) ; 
        if(is_valid(s , 0 ,s.size() -1)) return 0;
        
         return solve(s, 0); }
};