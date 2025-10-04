class Solution {
public:
    int maxArea(vector<int>& h) {
    
        int ans =0 ; 
       int start =0 ; 
       int end = h.size() -1 ;
       while(start<end)
       {
        int cur = (end -start) * min(h[start] , h[end]);
        ans = max(ans , cur);
        if(h[start] > h[end])
        {
            end--;
        }else 
        {
            start ++;
        }
       }
    return ans ; 
    }
};