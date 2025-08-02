class Solution {
public:
    int db[2000][2000] ; 
    int solve(vector<int>& nums, int i, int j, int t) {
        if (j - i <=0)
            return 0;

        if(db[i][j]!= -1) return db[i][j] ; 
        int ans = 0;
        if (i + 2 <= j) {
            if (nums[i] + nums[i + 1] == t)
                ans = solve(nums, i + 2, j, t) + 1;
        }

        if (j - 2 >= i) {
            if (nums[j] + nums[j - 1] == t)
                ans = max(solve(nums, i, j - 2, t) + 1, ans);
        }
        if (i + 1 <= j) {
            if (t == nums[i] + nums[j])
             {
                
                   ans = max(ans, solve(nums, i + 1, j - 1, t) + 1);
             }
        }
        

        return db[i][j] = ans;
    }
    int maxOperations(vector<int>& nums) {
        memset(db , -1 , sizeof db) ;
        int ans = 0;
        int i = 0;
        int j = nums.size() - 1;
        if (i + 2 < nums.size()) {
            ans =
                max(ans,
                    solve(nums, 2, j, nums[i] + nums[i + 1]) + 1);
        }
        if (j - 2 >= 0) {

            ans = max(ans, solve(nums, i, j - 2, nums[j] + nums[j - 1]) + 1);
        }
        ans = max(ans, solve(nums, i + 1, j - 1, nums[i] + nums[j]) + 1);

        return ans;
    }
};