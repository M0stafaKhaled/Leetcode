class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int cur = 0;
        int sum = 0;

        for (int i = 0; i < n; i++) {

            sum += nums[i];
        }
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            cur += nums[i];
            int right = sum - cur;
            int diff = cur - right;
            if (diff % 2 == 0)
                ans++;
        }

        return ans;
    }
};