class Solution {
public:

    vector<vector<int>> db ; 
    int solve(string& s, int i, int j) {

        if(i>j) return 0; 
        if (i == j)
            return 1;
           
        if (s[i] == s[j]) {

            return solve(s  , i+1 , j-1) +2 ; 
        }
        if(db[i][j] != -1) return db[i][j] ; 
        return db[i][j] =  max(solve(s , i+1 , j) , solve(s , i  , j-1)) ; 
    }
    int longestPalindromeSubseq(string s) {
            db=vector<vector<int>>(s.size() , vector<int>(s.size()  , -1)) ; 

        return max(solve(s , 0 , s.size() -1)  , 1) ; 
    }
};