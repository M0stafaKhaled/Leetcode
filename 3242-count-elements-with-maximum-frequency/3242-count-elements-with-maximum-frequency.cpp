class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {

        int maxs = 0;
        int ans = 0;
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            maxs = max(++map[nums[i]], maxs);
        }

        for (int i = 0; i < nums.size(); i++) {
            ans += map[nums[i]] == maxs ? 1 : 0;
        }
        return ans;
    }
};