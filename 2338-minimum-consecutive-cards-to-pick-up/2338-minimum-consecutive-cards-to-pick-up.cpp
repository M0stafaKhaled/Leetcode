class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int , int> map ; 
        int start =0 ; 
        int ans = INT_MAX ; 
        for(int i =0 ; i<cards.size() ; i++)
        {
            int cur = cards[i] ; 
            map[cur] ++; 
            while(map[cur] >1 && i>start)
            {   ans = min((i -start)+1 , ans) ;
                int pre = cards[start++] ; 
                map[pre] -- ;  
            }
        }
        return ans == INT_MAX ? -1 : ans ; 
    }
};