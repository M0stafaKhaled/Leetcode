class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        int ans = -1;
        int left = 0;
        for (int i = 0; i < nums.size(); i++) {
            int right = sum - nums[i];
            sum = right;
            if (left == right)
                return i;
            left += nums[i];
        }

        return ans;
    }
};