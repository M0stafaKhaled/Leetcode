class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
       unordered_map<int , int> map ; 
        int n = nums.size() ; 
         long long sum = accumulate(nums.begin() , nums.end() ,0LL) ;
       map[0] = -1 ; 
       
        int ans =n; 
       int cur =0 ; 
       if(sum%p ==0) return 0 ; 
        for(int i =0 ; i<n ; i++)
        {
            cur= (cur + (nums[i])) %p  ;
            int s = ((cur - (sum%p))+p) %p ; 
           if(map.find(s) != map.end())
           {
              
            ans = min(ans , i- map[s]);   
           }
           map[cur] = i ;
           
           
          
        }
        if(ans==n) return -1 ; 
        return ans ;
        
    }
};