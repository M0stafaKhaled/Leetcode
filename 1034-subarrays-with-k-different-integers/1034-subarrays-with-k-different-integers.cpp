class Solution {
public:
    int solve(vector<int>& nums, int k) {
        unordered_map<int, int> map;

        int ans = 0;
        int start = 0;
        int end = 0;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
            int sub = 0;

            while (i >= start && map.size() > k) {
                int cur = nums[start];
                map[cur]--;
                if (map[cur] == 0) {
                    map.erase(cur);
                }
                start++;
            }

            ans += (i - start) + 1;
        }

        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {

        return solve(nums, k) - solve(nums, k - 1);
    }
};