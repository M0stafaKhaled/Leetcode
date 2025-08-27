class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        unordered_map<int, int> map;
        map[nums[0]]++;
        int start = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            map[nums[i]]++;
            if (nums[i + 1] > nums[start]) {
                ans++;
                start++;
            }
        }

        return ans;
    }
};