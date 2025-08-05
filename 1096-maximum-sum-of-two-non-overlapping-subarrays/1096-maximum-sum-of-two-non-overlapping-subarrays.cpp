class Solution {
public:
    int db[2001] ; 
    int ans = 0;
    int solve(vector<int>& nums, int firstLen) {
        int sum1 = 0;
        int idx = 0;
        int f = 0;
        for (int i = nums.size() -1; i>(nums.size() - firstLen)-1 ; i--) {
          // cout<<i<<" " ;
         
            sum1 += nums[i];
             db[i] = sum1 ; 
        }
      
        db[(nums.size() - firstLen)-1]  = sum1 ; 
        f = sum1;
        for (int i =(nums.size() - firstLen)-1; i>=0 ; i--) {
          //  cout<<i << " " << i + firstLen  <<endl  ; 
           //  cout<<i + firstLen -1<<" " ; 
            sum1 -= nums[i + firstLen ];
            sum1 += nums[i];
          //  cout<<sum1 <<endl ; 
            f = max(f, sum1);
             db[i] = f ; 
        }
    
        for(int i =0 ; i<nums.size() ; i++)
        {
            cout<<db[i] << " " ; 
        }

    

        return f;
    }
    int solve2(vector<int>nums, int sz, int sec, vector<int>& nums2) {
        int sum = 0;
        for (int i = 0; i < sz; i++) {

            sum += nums[i];
            //nums[i] = -1000;
        }
        ans = max(ans, sum + db[sz]);
       
        for (int i = sz; i < nums.size(); i++) {
           // nums[i - sz] = nums2[i - sz];
            sum -= nums[i - sz];
            sum += nums[i];
           // nums[i] = -1000;
            
            ans = max(ans, sum + db[i+1]);

            
        }
        return ans;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {

        int m1 = min(firstLen , secondLen);
        int m2 = max(firstLen , secondLen) ;
        memset(db , 0 , sizeof db) ; 
        solve(nums , m1) ; 
        int ans1 =  solve2(nums, m2, m1, nums);
         memset(db , 0 , sizeof db) ; 
         solve(nums , m2) ; 
         int ans2 =  solve2(nums, m1, m2, nums);

         return max(ans1 , ans2) ; 
    }
};