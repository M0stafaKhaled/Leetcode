class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
       unordered_set<int> st ; 
       int sum =0 ; 
       int n = nums.size();
       int sh  = (n*(n+1))/2;
       int num =0 ; 
        for(int i =0 ; i<nums.size(); i++)
        {
           sum+=nums[i] ; 
           if(st.count(nums[i]))   num = nums[i] ; 
           st.insert(nums[i]) ; 
        }

        return {num , sh-(sum-num)} ; 
    }
};