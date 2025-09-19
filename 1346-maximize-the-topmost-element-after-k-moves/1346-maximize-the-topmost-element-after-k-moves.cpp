class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {

        if (nums.size() == 1) {
            if (k % 2 == 0)
                return nums[0];
            return -1;
        }
        if (k == 1) {
            return nums[1];
        }
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < min(k - 1, n); i++) {

            ans = max(ans, nums[i]);
        }

        if (k < nums.size()) {
            ans = max(ans, nums[k]);
        }
        return ans;
    }
};