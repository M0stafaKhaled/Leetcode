class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int z = 0;
        int o = 0;

        for (int i = 0; i < nums.size(); i++) {
            z += nums[i] % 2 == 0;
            o += nums[i] % 2 == 1;
        }
       
        int start = 0;
        while (z--) {
            nums[start++] = 0;
        }

        while (o--) {
            nums[start++] = 1;
        }

        return nums;
    }
};