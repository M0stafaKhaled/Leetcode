class Solution {
public:
    vector<vector<int>> ans ; 
    void solve(int idx , int n , vector<int>& cur)
    {
        if(idx > n) return ; 
        vector<int> next(idx);
        next[0] =1 ; 
        for(int i = 1 ; i<idx-1 ; i++)
        {
            next[i] = cur[i-1] + cur[i] ; 
        }
        next[idx-1] = 1 ; 
        ans.push_back(next) ;
        solve(idx+1 , n , next) ; 
    } 
    vector<vector<int>> generate(int numRows) {
         ans.push_back({1}) ; 
        if(numRows ==1) return  ans ; 
        
        vector<int> cur(1 , 1) ; 
        solve(2 , numRows , cur) ; 

        return ans ;  
         
    }
};