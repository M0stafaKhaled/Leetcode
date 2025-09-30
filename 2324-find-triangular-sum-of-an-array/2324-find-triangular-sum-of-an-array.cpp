class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int f = nums.size();
        while (f > 1) {
            for (int i = 0; i < f - 1; i++) {
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
            f--;
        }

        return nums[0];
    }
};