class Solution {
public:
    vector<int> solve(int n)
    {
        if(n==0) return {1} ; 

        vector<int> cur = solve(n-1) ;
        vector<int> next(n+1 , 1) ;
        for(int i =1 ; i<cur.size() ; i++)
        {
            next[i]=cur[i-1] +cur[i];
        }

        return next ; 
    }
    vector<int> getRow(int rowIndex) {
        return solve(rowIndex);
    }
};