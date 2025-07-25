class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> st ; 
        int ans =0 ; 
        int f  = INT_MIN; 
        for(int i =0 ; i<nums.size() ; i++)
        {
            f  = max(f , nums[i]) ; 
            if(nums[i] >=0)
            {
                if(st.find(nums[i]) == st.end()) ans+=nums[i];
                  st.insert(nums[i]) ; 

            }
        }


        if(st.size()) return ans ; 
        return f ; 
    }
};