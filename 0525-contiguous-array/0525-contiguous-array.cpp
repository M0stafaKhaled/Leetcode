class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        int ans = 0;
        unordered_map<int, int> map;
        int sum = 0;
        map[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i] == 1 ? 1 : -1;
            if (map.find(sum) != map.end()) {
                ans = max(ans, (i - map[sum]) + 1);
            } else {
                map[sum] = i+1;
            }
        }
        return ans;
    }
};