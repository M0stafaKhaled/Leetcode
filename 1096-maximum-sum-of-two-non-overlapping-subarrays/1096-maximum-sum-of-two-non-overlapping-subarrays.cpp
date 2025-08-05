class Solution {
public:
  
    int ans = 0;
    int solve(vector<int>& nums, int firstLen) {
        int sum1 = 0;
        int idx = 0;
        int f = 0;
        for (int i = 0; i < firstLen; i++) {
            sum1 += nums[i];
        }
        
        f = sum1;
        for (int i = firstLen; i < nums.size(); i++) {
            sum1 -= nums[i - firstLen];
            sum1 += nums[i];
          
            f = max(f, sum1);
        }

     

        return f;
    }
    int solve2(vector<int>nums, int sz, int sec, vector<int>& nums2) {
        int sum = 0;
        for (int i = 0; i < sz; i++) {

            sum += nums[i];
            nums[i] = -1000;
        }
        ans = max(ans, sum + solve(nums, sec));
       
        for (int i = sz; i < nums.size(); i++) {
            nums[i - sz] = nums2[i - sz];
            sum -= nums[i - sz];
            sum += nums[i];
            nums[i] = -1000;
           
            ans = max(ans, sum + solve(nums, sec));
        }
        return ans;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
     

        return solve2(nums, secondLen, firstLen, nums);
    }
};