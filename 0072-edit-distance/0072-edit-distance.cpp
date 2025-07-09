class Solution {
public:
    vector<vector<int>> db ; 
    int solve(string word1, string word2 , int i , int j)
    {
        if(i == word1.size() && j==word2.size()) return 0 ; 

        if(i == word1.size()) return word2.size() - j ; 
        if(j == word2.size()) return word1.size() - i ;
        if(db[i][j] != -1 ) return db[i][j] ; 

        if(word1[i] == word2[j]) 
        {
            return solve(word1 , word2 , i+1 , j+1) ; 
        } 
        int  ans = solve(word1 , word2 , i+1 , j+1)+1 ; 
        ans =  min( solve(word1 , word2 , i+1 , j)+1 , min( solve(word1 , word2 , i , j+1)+1 , ans) ) ; 
        
        return db[i][j] =  ans ; 
    }
    int minDistance(string word1, string word2) {
        
        db = vector<vector<int>>(word1.size() , vector<int>(word2.size() , -1)); 
        return solve(word1 , word2 , 0 , 0) ; 
    }
};