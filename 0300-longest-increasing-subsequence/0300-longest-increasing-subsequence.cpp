class Solution {
public:
    int db[2501] ;
    int solve(vector<int>& nums , int i)
    {
        if(i==nums.size()) return 0 ; 
        if(db[i] != -1) return db[i] ; 
       // int ans = solve(nums , i+1) ; 
        int cur =0 ; 
        for(int j = i+1 ; j<nums.size() ; j++)
        {
            if(nums[j] > nums[i])
            {
                cur = max(solve(nums , j)+1 , cur);
            }
        }

        return db[i] = cur ;
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(db , -1 , sizeof db) ; 


        int ans =0 ;
        for(int i =0 ; i<nums.size() ; i++)
        {
            int cur = solve(nums, i)+1;
            ans = max(ans ,  cur);
        }
        return  ans;
    }
};