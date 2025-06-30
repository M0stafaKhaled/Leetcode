class Solution {
public:
    int findLHS(vector<int>& te) {
        unordered_map<int , int> map ; 
        for(int i =0 ; i<te.size() ;i++)
        {          
             map[te[i]]++;
        }
         
        int ans =0 ; 
        for(int i =0 ; i<te.size() ; i++)
        {
            if(map.find(te[i]+1) != map.end()) 
            {
                ans = max(ans,  map[te[i]] + map[te[i] +1]);
            }
        }

        return ans ; 
    }
};