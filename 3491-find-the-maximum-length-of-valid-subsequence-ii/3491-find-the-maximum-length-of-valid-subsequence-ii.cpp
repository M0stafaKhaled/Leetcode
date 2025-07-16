class Solution {
public:
 
  

    int maximumLength(vector<int>& nums, int k) {
       
        int ans = 0;
        int db[1000][1001];
        memset(db , 0 , sizeof db) ; 
       for(int i=0;i<nums.size();++i){
            for(int j=0;j<i;++j){
                int t=(nums[i]+nums[j])%k;
                db[i][t]=db[j][t]+1;
                ans=max(ans,db[i][t]);
            }
        }
        
        
        return ans+1;
    }
};