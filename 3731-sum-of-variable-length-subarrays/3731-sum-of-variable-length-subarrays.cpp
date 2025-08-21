class Solution {
public:
    int subarraySum(vector<int>& nums) {
        vector<int> pre(nums.size());
        pre[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            pre[i] = pre[i - 1] + nums[i];
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int start = i - nums[i] ;
            if(start >=1)
            {
                ans+=( pre[i] - pre[start -1] );
            } else 
                 ans+=pre[i] ; 
        }

        return ans ; 
    }
};