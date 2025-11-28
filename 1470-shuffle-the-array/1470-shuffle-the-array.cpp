class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {

        vector<int> ans(nums.size());
        int st = 0;
        for (int i = 0; i < nums.size() / 2; i++) {
            ans[st++] = nums[i];
            ans[st++] = nums[i + n];
        }

        return ans;
    }
};