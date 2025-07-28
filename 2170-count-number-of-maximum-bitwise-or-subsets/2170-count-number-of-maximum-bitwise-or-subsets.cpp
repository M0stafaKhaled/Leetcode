class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int max_or = 0;
        for (int i = 0; i < nums.size(); i++) {
            max_or |= nums[i];
        }

        int mask = 1 << (nums.size());

        int ans = 0;
        for (int i = 0; i < mask; i++) {
            int cur = 0;

            for (int j = 0; j < nums.size(); j++) {
                if ((i >> j) & 1) {
                    cur |= nums[j];
                }
            }
            if (cur == max_or) {
                ans++;
            }
        }

        return ans;
    }
};