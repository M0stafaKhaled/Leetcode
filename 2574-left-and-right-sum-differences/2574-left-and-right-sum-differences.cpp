class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        vector<int> ans(n);

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        int left = 0;

        for (int i = 0; i < n; i++) {
            sum = sum - nums[i];
            ans[i] = abs(sum - left);
            left += nums[i];
        }

        return ans;
    }
};