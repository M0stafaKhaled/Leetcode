class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> pre(arr.size() +1) ; 
        for(int i =1 ; i<=arr.size() ; i++)
        {
            pre[i]= arr[i-1]^pre[i-1]  ;  
        }

        vector<int> ans(queries.size())  ;
        for(int i =0 ; i<queries.size() ; i++)
        {
            int a =queries[i][0] ; 
            int b = queries[i][1] ; 
            ans[i] = pre[a] ^ pre[b+1] ; 
        }

        return ans ; 
    }
};