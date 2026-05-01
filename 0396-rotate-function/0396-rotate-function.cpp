class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        // 4326
        // 6432
        // 2643
        // 3264

        int sum = 0;
        int cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            cur += (nums[i] * i);
        }

        int ans = cur;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            cur = (cur - sum) + (n * nums[i]);
            ans = max(ans, cur);
        }
        return ans;
    }
};