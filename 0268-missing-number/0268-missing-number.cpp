class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum1 = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum1 ^= nums[i];
        }
        int sum2 = 0;
        for (int i = 0; i <= n; i++) {
            sum2 ^= i;
        }

        return sum2 ^ sum1;
    }
};