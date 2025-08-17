class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        long long  d =0 ; 
        for(int i =0 ; i<nums.size() ; i++)
        {
            d^=nums[i] ; 
        }
        long long  f = d & -d ; 
        int a =0 ;
        int b =0 ; 
        for(int  i =0 ;i<nums.size() ; i++)
        {
            if(nums[i]&f)
            {
                a^=nums[i] ; 
            }else
             b^=nums[i] ; 
        }
        //110
        //101
        //011
        //100


        cout<<d<<endl ; 
    return {a,b} ; 
    }
};