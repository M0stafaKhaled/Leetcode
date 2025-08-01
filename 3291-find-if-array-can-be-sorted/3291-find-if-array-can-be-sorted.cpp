class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        vector<int> copy = nums;

        sort(copy.begin(), copy.end());

        for (int i = 0; i < nums.size(); i++) {
            // __builtin_popcount(nums[i])
            int h = __builtin_popcount(nums[i]);
            int cur = i;

            while (i + 1 < nums.size() &&
                   __builtin_popcount(nums[i + 1]) == h) {
                i++;
            }

            sort(nums.begin() + cur, nums.begin() + (i + 1));
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != copy[i])
                return 0;
        }

        return 1;
    }
};