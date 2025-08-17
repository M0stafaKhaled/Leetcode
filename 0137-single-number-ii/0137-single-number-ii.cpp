class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int all = 0;
        // 01
        // 01
        int ones = 0;
        int twos = 0;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            ones = (ones ^ x) & ~twos;
            twos = (twos ^ x) & ~ones;
        }
        return ones;
    }
};