class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_and = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > max_and) {
                max_and = nums[i];
            }
        }

        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int cur = 0;
            while (i < nums.size() && nums[i] == max_and) {
                cur++;
                i++;
            }
            ans = max(ans, cur);
        }

        return ans;
    }
};