class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int cur = 0;
        int ans = 0;
        int start = 0;
        int end = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 1) {
                cur++;
            }

            while (cur > k) {
                cur -= nums[start] % 2;
                start++;
            }

            if (cur == k) {
                end = max(start, end);
                while (end < nums.size() && nums[end] % 2 == 0) {
                    end++;
                }

                ans += end - start + 1;
            }
        }

        return ans;
    }
};