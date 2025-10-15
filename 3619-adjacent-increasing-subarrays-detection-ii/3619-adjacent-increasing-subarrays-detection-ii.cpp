class Solution {
public:
    bool solve(const vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2 * k)
            return false;

        vector<int> run(n, 1);

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i + 1] > nums[i])
                run[i] = run[i + 1] + 1;
            else
                run[i] = 1;
        }
        for (int i = 0; i + 2 * k <= n; i++) {
            if (run[i] >= k && run[i + k] >= k)
                return true;
        }

        return false;
    }
    int maxIncreasingSubarrays(vector<int>& nums) {
        int start = 0;
        int end = nums.size();
        int ans = 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            // cout << mid << " " << endl;
            if (solve(nums, mid)) {
                ans = max(ans, mid);
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return ans;
    }
};