class Solution {
public:
    int countHillValley(vector<int>& nums) {
        unordered_map<int, int> map;
        int ans = 0;
        for (int i = 1; i < nums.size() - 1; i++) {
            int count = 1;
            int cur = nums[i];
            int first = i - 1;
            int last = i + 1;

            while (i + 1 < nums.size() && cur == nums[i + 1]) {
                i++;
            }
            if (i + 1 == nums.size())
                return ans;
            // hill

            if (cur > nums[first] && cur > nums[i + 1]) {
                ans += count;
            }

            if (cur < nums[first] && cur < nums[i + 1])
                ans += count;
        }
        return ans;
    }
};