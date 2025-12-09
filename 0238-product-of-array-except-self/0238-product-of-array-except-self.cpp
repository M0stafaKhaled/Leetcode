class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);
        vector<int> suf(n);
        pre[0] = 1;
        suf[n - 1] = 1;
        for (int i = 1; i < nums.size(); i++) {
            pre[i] = pre[i - 1] * nums[i - 1];

            int cur = (n - 1) - i;

            suf[cur] = suf[cur + 1] * nums[cur + 1];
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = pre[i] * suf[i];
        }

        return ans;
    }
};