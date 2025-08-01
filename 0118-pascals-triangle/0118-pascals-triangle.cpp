class Solution {
public:
     vector<vector<int>> solve(int idx)
    {
        if(idx == 1) 
        {
            return {{1}} ; 
        }
        vector<vector<int>> prev  = solve(idx -1) ; 

        vector<int> next(idx , 1);
        for(int i =1 ;  i<idx-1 ; i++)
        {
            next[i] = prev.back()[i-1] +prev.back()[i] ; 
         }
         prev.push_back(next);

       return prev ;  
    } 
    vector<vector<int>> generate(int numRows) {
        return solve(numRows) ;  
         
    }
};