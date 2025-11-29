class Solution {
public:
    int sign(int num) {
        if (num > 0)
            return 1;
        if (num < 0)
            return -1;
        return 0;
    }
    int arraySign(vector<int>& nums) {
        int s = 1;
        for (int i = 0; i < nums.size(); i++) {
            s *= sign(nums[i]);
        }

        return s;
    }
};