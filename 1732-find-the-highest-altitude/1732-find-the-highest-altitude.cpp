class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> pre (gain.size() ,0);
        for(int i =0 ; i<gain.size() ;i++)
        {
           pre[i] = ( i==0  ? 0 :pre[i-1] ) + gain[i];
        }
        int ans =0 ; 
        for(int i=0 ; i<pre.size() ;i++)
        {
            ans = max(ans ,pre[i]);
        }
        return ans;
    }
};