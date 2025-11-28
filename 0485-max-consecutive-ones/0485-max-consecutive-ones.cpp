class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;

        int cur = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                ans = max(ans, cur);
                cur = 0;
            } else {
                cur++;
                ans = max(ans, cur);
            }
        }

        return ans;
    }
};