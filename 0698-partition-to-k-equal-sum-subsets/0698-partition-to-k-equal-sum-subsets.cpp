class Solution {
public:
    bool vist[17];
    bool solve(vector<int>& nums, int target, int idx, int sum, int k ) {

        if (sum > target)
            return 0;
        if(k ==0) return true ; 
        if (sum == target) {
          
         return solve( nums ,target , 0 , 0  , k-1);
        }
        if (idx == nums.size())
            return false;
        if (vist[idx])
            return solve(nums, target, idx + 1, sum , k);

        vist[idx] = true ;
        bool ans = solve(nums, target, idx + 1, sum + nums[idx] , k);
        vist[idx]= false;
        ans |= solve(nums, target, idx + 1, sum , k);

        return ans;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if (k == 1)
            return 1;
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];

        int n = nums.size();
        if (sum % k != 0)
            return false;
        vector<int> cur;
       
        return solve(nums, sum / k, 0, 0 , k);
    }
};